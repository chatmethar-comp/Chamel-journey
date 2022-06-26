#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=400;
int t, x, n, a[mxN], ans;
ar<int,2> dp[mxN][mxN];
int main()
{
    cin >> t >> x;
    while(t--){
        memset(dp,0,sizeof(dp));
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i];
            dp[i][i]={1,1};
        }
        for(int s=2;s<=n;s++){
            for(int i=1;i+s-1<=n;i++){
                int j=i+s-1;
                dp[i][j]={dp[i+1][j][0]+1,1};
                for(int k=i+1;k<=j;k++){
                    if(a[i]==a[k]){
                        ar<int,2> tmp;
                        if(dp[k][j][1]+1<=x){
                            tmp={dp[i+1][k-1][0]+dp[k][j][0],dp[k][j][1]+1};
                        } else {
                            tmp={dp[i+1][k-1][0]+dp[k][j][0],1};
                        }
                        dp[i][j]=min(dp[i][j],tmp);
                    }
                }
            }
        }
        ans=max(ans,dp[1][n][0]);
    }
    cout << ans;
    return 0;
}
