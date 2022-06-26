#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
int dist[110][110][2];
int n, s, e, d, m, a[110], u, v, w, c, f;
struct A{
    int u, w, f, c;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
priority_queue<A> dij;
vector<array<int,2>> g[110];
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    cin >> s >> e >> d >> m;
    while(m--){
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    memset(dist,0x3f,sizeof(dist));
    dij.push({s,0,0,0});
    while(dij.size()){
        u=dij.top().u;
        w=dij.top().w;
        f=dij.top().f;
        c=dij.top().c;
        dij.pop();
        if(!c&&w<dist[u][d][1])
            dij.push({u,dist[u][d][1]=w,d,1});
        if(f+1<=d&&w+a[u]<dist[u][f+1][c])
            dij.push({u,dist[u][f+1][c]=w+a[u],f+1,c});
        for(auto x : g[u]){
            if(f>=x[1]&&w<dist[x[0]][f-x[1]][c])
                dij.push({x[0],dist[x[0]][f-x[1]][c]=w,f-x[1],c});
        }
    }
    cout << dist[e][d][1];
    return 0;
}
