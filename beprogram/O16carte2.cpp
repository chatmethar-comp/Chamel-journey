#include<bits/stdc++.h>
using namespace std;
#define ar array
const int mxN=500;
int t, n, x, a[mxN], ans=0;
ar<int,2> dp[mxN][mxN];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> t >> x;
    while(t--){
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            dp[i][i]={1,1};
        }
        for(int l=2;l<=n;l++)
            for(int i=1;i+l-1<=n;i++){
                int j=i+l-1;
                if(i==j)
                    continue;
                dp[i][j]={dp[i+1][j][0]+1,1};
                for(int k=i+1;k<=j;k++){
                    if(a[i]==a[k]){
                        ar<int,2> t1;
                        if(dp[k][j][1]+1<=x)
                            t1={dp[i+1][k-1][0]+dp[k][j][0],dp[k][j][1]+1};
                        else
                            t1={dp[i+1][k-1][0]+dp[k][j][0]+1,1};
                        dp[i][j]=min(dp[i][j],t1);
                    }
                }
            }
        ans=max(ans,dp[1][n][0]);
    }
    cout << ans;
    return 0;
}
