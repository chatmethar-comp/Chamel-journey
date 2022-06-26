#include<bits/stdc++.h>
using namespace std;
const int mxN=1e5;
#define ll long long
#define ar array
int n, m, k, a[mxN+1];

bool e(ll x)
{
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll s=0, c=0;
    for(int i=1;i<=n;i++){
        s+=a[i];
        pq.push(a[i]);
        if(pq.size()>k){
            s-=pq.top();
            pq.pop();
        }
        if(pq.size()==k&&s>=x){
            c++;
            s=0;
            while(pq.size())
                pq.pop();
        }
        if(c==m)
            return 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    ll l=0, r=1e12;
    while(l<r){
        ll m=(l+r)>>1;
        if(e(m))
            l=m+1;
        else
            r=m;
    }
    cout << l-1;
    return 0;
}
