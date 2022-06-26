#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=1e5, MOD=1e9+7;
int n, m, a[mxN+1];
ll dp[mxN+1][101], ans=0;
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    if(a[1]){
        dp[1][a[1]]=1;
    } else {
        for(int i=1;i<=m;i++)
            dp[1][i]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=dp[i-1][j];
            if(j!=1)
                dp[i][j]+=dp[i-1][j-1];
            if(j!=m)
                dp[i][j]+=dp[i-1][j+1];
        }
        if(a[i]){
            for(int j=0;j<=m;j++){
                if(j!=a[i])
                    dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    for(int i=1;i<=m;i++)
        ans=(ans+dp[n][i])%MOD;
    cout << ans;
    return 0;
}
