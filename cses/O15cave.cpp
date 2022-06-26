#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=2e3;
int n, p, en, e, l, h;
vector<ar<ll,2>> adj[mxN];
ll d[mxN][mxN];
priority_queue<ar<ll,3>,vector<ar<ll,3>>,greater<ar<ll,3>>> pq;
int main()
{
    memset(d,0x3f,sizeof(d));
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> p >> en >> e;
    for(int i=0,a,b,c;i<e;i++){
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
    }
    d[p][0]=0;
    pq.push({0,p,0});
    while(pq.size()){
        ll w=pq.top()[0];
        ll u=pq.top()[1];
        ll s=pq.top()[2];
        pq.pop();
        if(d[u][s]<w)
            continue;
        for(ar<ll,2> v : adj[u]){
            ll ns=(u==p?s:s+1);
            if(d[u][s]+v[0]<d[v[1]][ns]){
                d[v[1]][ns]=d[u][s]+v[0];
                pq.push({d[v[1]][ns],v[1],ns});
            }
        }
    }
    cin >> l;
    while(l--){
        cin >> h;
        ll ans=INT_MAX;
        for(int i=0;i<=n;i++)
            if(d[en][i]!=0x3f)
                ans=min(ans,d[en][i]+h*i);
        cout << ans << " ";
    }
    return 0;
}
