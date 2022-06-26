#include<bits/stdc++.h>
using namespace std;
#define ar array
const int mxN=30;
int t, n, x, ans=0, a[mxN];
ar<int,2> dp[mxN+1][mxN+1];
int main()
{
    cin >> t >> x;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i];
//            dp[i][i]={1,1};
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){

                if(a[i]==a[j]){
                    ar<int,2> t1, t2;
                    if(dp[i+1][j][1]+1<=x)
                        t1={dp[i+1][j][0],dp[i+1][j][1]+1};
                    else
                        t1={dp[i+1][j][0]+1,1};
                    if(dp[i][j-1][1]+1<=x)
                        t2={dp[i][j-1][0],dp[i][j-1][1]+1};
                    else
                        t2={dp[i][j-1][0]+1,1};
                    dp[i][j]=min(t1,t2);
                    for(int k=i;k<=j;k++){
                        dp[i][j]=min(dp[i-k][j],dp[])
                    }
                }
                else {
                    ar<int,2> t1, t2;
                    dp[i][j]={min(dp[i][j-1][0],dp[i+1][j][0])+1,1};
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << dp[i][j][0] << " " << dp[i][j][1] << "\t";
            }
            cout << endl << endl;
        }
        ans=max(ans,dp[0][n-1][0]);
    }
    cout << ans << endl;
    return 0;
}
