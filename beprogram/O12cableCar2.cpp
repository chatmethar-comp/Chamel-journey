#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=2.51e3;
ll n, m, u, v, w, p[mxN], ans, st, en, me;
vector<ar<ll,3>> edges;
ll Find(ll i)
{
    if(p[i]==i)
        return i;
    return p[i]=Find(p[i]);
}

int main()
{
    cin >> n >> m;
    for(ll i=0;i<m;i++){
        cin >> u >> v >> w;
        edges.push_back({w-1,u,v});
    }
    cin >> st >> en >> me;
    sort(edges.begin(), edges.end(), greater<>());
    iota(p+1,p+n+1,1);
    for(auto [w,u,v] : edges){
        ll pu=Find(u), pv=Find(v);
        if(pu==pv)
            continue;
        p[pv]=pu;
        ans=w;
//        cout << "ans: " << ans << endl;
        if(Find(st)==Find(en))
            break;
    }
    cout << ceil((float)me/ans);
    return 0;
}










