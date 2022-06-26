#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=2e5;
ll n, a, b, mx=0, c=0;
set<ar<ll,2>> s;
int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        s.insert({2*a,1});
        s.insert({2*b+1,-1});
    }
    for(ar<ll,2> a : s){
        c+=a[1];
        mx=max(c,mx);
    }
    cout << mx;
    return 0;
}
