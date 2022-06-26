#include<bits/stdc++.h>
using namespace std;
const int mxN=1e5+1;
int n, m, a, b, ds[mxN], p[mxN];
vector<int> adj[mxN], ans;

void dfs(int u)
{
    for(int v : adj[u]){
        if(v!=p[u]){
            p[v]=u;
            dfs(v);
        }
    }
}

int find(int u)
{
    if(ds[u]<0)
        return u;
    ds[u]=find(ds[u]);
    return ds[u];
}

bool merge(int u, int v)
{
    u=find(u);v=find(v);
    if(u==v)
        return false;
    if(ds[u]<ds[v])
        swap(u,v);
    ds[v]+=ds[u];
    ds[u]=v;
    return true;
}

int main()
{
    memset(ds,-1,sizeof(ds));
    cin >> n >> m;
    for(int i=0;i<m;++i){
        cin >> a >> b;
        if(!merge(a,b)){
            dfs(a);
            int u=b;
            while(u!=0){
                ans.push_back(u);
                u=p[u];
            }
            int K=ans.size();
            cout << K+1 << endl;
            for(int j=0;j<K;j++){
                cout << ans[j] << " ";
            }
            cout << b;
            return 0;
        } else {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
