#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7, mxN=1e6+5;
int n, dp[mxN];
int main()
{
    cin >> n;
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(i<j){
                continue;
            }
            dp[i]=(dp[i]+dp[i-j])%MOD;
        }
    }
    cout << dp[n];
    return 0;
}
