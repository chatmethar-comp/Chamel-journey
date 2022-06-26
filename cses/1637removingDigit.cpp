#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=1e6+5;
ll n, dp[mxN];
int main()
{
//    memset(dp,0,sizeof(dp));
    cin >> n;
    for(ll i=1;i<=n;i++){
        ll k=i;
        dp[i]=1e9;
        while(k){
            dp[i]=min(dp[i],dp[i-k%10]+1);
            k/=10;
        }
    }
    for(ll i=1;i<n;i++){
        cout << i << " " << dp[i] << endl;
    }
    cout << dp[n];
    return 0;
}
