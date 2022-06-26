#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, x, h[1005], s[1005];
ll dp[100005];

int main()
{
    cin >> n >> x;
    for(ll i=0;i<n;i++)
        cin >> h[i];
    for(ll i=0;i<n;i++)
        cin >> s[i];
    for(ll i=0;i<n;i++){
        for(ll j=x;j>=h[i];j--)
            dp[j]=max(dp[j],dp[j-h[i]]+s[i]);
//        for(ll j=0;j<=x;j++){
//            cout << dp[j] << " ";
//        }
//        cout << endl;
    }
    cout << dp[x];
    return 0;
}
