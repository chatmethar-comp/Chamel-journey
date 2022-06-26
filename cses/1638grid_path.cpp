#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=1e3;
const int M=1e9+7;
ll n, dp[mxN][mxN];
char c[mxN][mxN];
int main()
{
    memset(dp,0,sizeof(dp));
    cin >> n;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin >> c[i][j];
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(c[i][j]=='*'){
                continue;
            }
            if(i==0&&j==0){
                dp[i][j]++;
                continue;
            }
            if(i==0){
                dp[i][j]+=dp[i][j-1];
                continue;
            }
            if(j==0){
                dp[i][j]+=dp[i-1][j];
                continue;
            }
            dp[i][j]+=(dp[i-1][j]+dp[i][j-1])%M;
        }
    }

    cout << dp[n-1][n-1];
    return 0;
}
