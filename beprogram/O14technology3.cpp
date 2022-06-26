#include<bits/stdc++.h>
using namespace std;
const int mxN=1e5, mxK=1e4;
int n, k, t, vis[mxN+1], ans=-1, timee=0;
vector<int> adj[mxN+1], p[mxK+1];

void dfs(int u)
{
    if(vis[u]==2){
        return;
    }
    if(vis[u]==1){
        timee=1e9;
        return;
    }
    if(vis[u]==0){
        vis[u]=1;
        for(int v : adj[u]){
            dfs(v);
        }
    }
    vis[u]=2;
    timee++;
}

int main()
{
    cin >> n >> k >> t;
    for(int i=1,a,m;i<=n;i++){
        cin >> a >> m;
        p[a].push_back(i);
        for(int j=0,x;j<m;j++){
            cin >> x;
            adj[i].push_back(x);
        }
    }
    for(int i=1;i<=k;i++){
        for(int v : p[i])
            dfs(v);
        if(timee>t)
            break;
        ans=i;
    }
    cout << ans;
}
