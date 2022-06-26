#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=1e6, MOD=1e9+7;
int t, n;
ll dp[mxN+1];
int main()
{
    dp[1]=2;
    dp[2]=8;
    for(int i=3;i<=mxN;i++)
        dp[i]=((6*dp[i-1]-7*dp[i-2])%MOD + MOD)N%MOD;
    cin >> t;
    while(t--){
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}
