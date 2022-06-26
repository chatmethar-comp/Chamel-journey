#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
ll n, e, u, v, w, RF, P, cost=0;
ar<ll,2> c[3010];
vector<pair<ll,ar<ll,2>>> edges;
ll p[3010];
vector<ll> ans;

int Find(ll i)
{
    if(p[i]==i)
        return i;
    return p[i]=Find(p[i]);
}
int main()
{
    cin >> n >> e;
    iota(p+1,p+n+1,1);
    for(ll i=0;i<e;i++){
        cin >> u >> v >> w >> RF;
        if(RF){
            ll pv=Find(v), pu=Find(u);
            if(pv==pu){
                continue;
            }
            p[pv]=pu;
            continue;
        }
        edges.push_back({w,{u,v}});
    }
    sort(edges.begin(), edges.end());
    for(auto edge : edges){
        ll pu=Find(edge.second[0]), pv=Find(edge.second[1]);
        if(pu==pv)
            continue;
        ans.push_back(edge.first);
        p[pv]=pu;
    }
    cin >> P;
    for(ll i=0;i<P;i++){
        cin >> c[i][1] >> c[i][0];
    }
    sort(c, c+P);
    for(ll i : ans){
        auto it=lower_bound(c,c+P,{i,0});
        cost+=(*it)[0];
    }
    cout << cost;
    return 0;
}
