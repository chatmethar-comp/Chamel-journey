#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mod=1e9+7;
const int mxN=1e9;
int t;

ll solve()
{
    ll r, c, a;
    cin >> r >> c;
    if(r>c)
        swap(r,c);
    a=(r-1)*r;
    a%=mod;
    a*=(r+1);
    a%=mod;
    a*=(2*c-r);
    a%=mod;
    while(a%12)
        a+=mod;
    a/=12;
    return a;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t;
    for(int i=1;i<=t;i++){
        cout << "Case #" << i << ": " << solve() << endl;
    }
    return 0;
}
