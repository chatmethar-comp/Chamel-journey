#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=2e5;
int n;
ar<int,3> a[mxN];
ll ldp=0;
set<ar<ll,2>> dp;
int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i][1] >> a[i][0] >> a[i][2];
    sort(a,a+n);
    dp.insert({0,0});
    for(int i=0;i<n;i++){
        auto itr=dp.lower_bound({a[i][1]});itr--;
        ldp=max(ldp,(*itr)[1]+a[i][2]);
        dp.insert({a[i][0],ldp});
    }
    cout << ldp;
    return 0;
}
