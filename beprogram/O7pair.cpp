#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const int mxN=1e5;
ll n;
ii p[mxN];

int main()
{
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> p[i].first >> p[i].second;
    }
    ll sum=0;
    sort(p,p+n);
    for(int i=n-1;i>=0;i--){
        for(int j=i-1;j>=0;j--){
            if(p[i].first>p[j].second&&p[i])
        }
    }
    cout << sum;
    return 0;
}
