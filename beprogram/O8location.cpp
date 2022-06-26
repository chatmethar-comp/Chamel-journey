#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxN=1005;
int n, m, k, a[mxN][mxN];
ll dp[mxN][mxN], mx=0;
int main()
{
    memset(dp,0,sizeof(dp));
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+a[i][j];
        }
    }
    for(int i=k+1;i<=n;i++){
        for(int j=k+1;j<=m;j++){
            mx=max(mx,dp[i][j]-dp[i][j-k]-dp[i-k][j]+dp[i-k][j-k]);
//            cout << dp[i][j]-dp[i][j-k]-dp[i-k][j]+dp[i-k][j-k] << "\t";
        }
//        cout << endl;
    }
    cout << mx;
    return 0;
}
