#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=2.5e6;
const int MOD=1e9+7;
ll n, x, c[100];
ll dp[mxN];
int main()
{
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    cin >> n >> x;
    for(ll i=0;i<n;i++){
        cin >> c[i];
    }
    for(ll i=0;i<=x;i++){
        for(ll j=0;j<n;j++){
//            dp[i+c[j]]+=dp[i]+1;
//            dp[i+c[j]]%=MOD;
            if(i-c[j]>=0)
                dp[i]+=dp[i-c[j]];
        }
//        cout << dp[i] << " ";
    }
    for(int i=0;i<x;i++)
        cout << dp[i] << " ";
    cout << endl;
    cout << dp[x];
    return 0;

}

