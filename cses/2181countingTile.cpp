#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=10, mxM=1e3, MOD=1e9+7;
int n, m;
ll dp[mxN+1][mxM+1][1<<mxN];
int main()
{
    cin >> n >> m;
    dp[n][0][0]=1;
    for(int i=1;i<=m;i++){
        for(int j=0;j<(1<<n);j++){
            dp[0][i][j<<1]=dp[n][i-1][j];
        }
        for(int j=1;j<=n;j++){
            int x=1<<(j-1), y=1<<j;
            for(int k=0;k<(1<<(n+1));k++){
                dp[j-1][i][k]%=MOD;
                if(k&x&&k&y)
                    continue;
                if(k&x)
                    dp[j][i][k^x]+=dp[j-1][i][k];
                else if(k&y)
                    dp[j][i][k^y]+=dp[j-1][i][k];
                else{
                    dp[j][i][k^y]+=dp[j-1][i][k];
                    dp[j][i][k^x]+=dp[j-1][i][k];
                }
            }
        }
    }
    for(int i=0;i<(1<<n);i++)
        cout << dp[n][m][i] << " ";
    cout << dp[n][m][0]%MOD;
    return 0;
}
