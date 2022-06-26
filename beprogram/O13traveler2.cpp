#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, st, en, k, ans, ans2, mn=1e9;
vector<ar<ll,2>> g[10010];
int dist[10010][10010];
struct A{
    int u, w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> dij;
void D(int u, int s)
{
    dis[s][u]=0;
    dij.push({u,0});
    while(dij.size()){
        int i=dij.top().u, w=dij.top().w;
        dij.pop();
        for(auto x : g[i]){
            if(dis[s][i]+x[1]<distg)
        }
    }
}

int main()
{
    cin >> n >> m;
    cin >> st >> en >> k;
    while(m--){
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    memset(dist,0x3f,sizeof(dist));
    D(st,0);D(en,1);
    for(int i=1;i<=n;i++){
        if(dist[0][i]<=k&&dist[1][i]<mn)
            mn=dist[1][i];
            ans=i, ans2=dist[0][i];
    }
    cout << ans << " " << ans2 << " " << mn;
    return 0;
}
