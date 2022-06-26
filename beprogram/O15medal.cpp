#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=5e5+5;
ll n, h[mxN], b[mxN], dx=INT_MIN, dn=INT_MAX;
int main()
{
    cin >> n;
    for(ll i=0;i<n;++i){
        cin >> h[i];
    }
    for(ll i=0;i<n;++i){
        cin >> b[i];
    }
    sort(h,h+n);
    sort(b,b+n);
    for(ll i=0;i<n;++i){
        if(dn>abs(h[i]+b[n-i-1]))
            dn=abs(h[i]+b[n-i-1]);
        if(dx<abs(h[i]+b[n-i-1]))
            dx=abs(h[i]+b[n-i-1]);
    }
    cout << dx-dn;
    return 0;
}
