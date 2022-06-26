#include<bits/stdc++.h>
using namespace std;
const int mxN=5e5;
int n, m, risk, ans, vis[mxN];
vector<int> adj[mxN];

int dfs(int u)
{
    vis[u]=1;
    int r=0, cycle=0;
    for(auto v : adj[u]){
        if(v==m)
            cycle=1;
        if(vis[v])
            continue;
        int tmp=dfs(v);
        if(!tmp)
            cycle=1;
        else
            r+=tmp;
    }
    if(u==m)
        return 0;
    if(r>ans){
        ans=r;
        risk=u;
    } else if(r==ans&&risk>u){
        risk=u;
    }
    if(cycle)
        return 0;
    return r+1;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m; m--;
    for(int i=0,a,b;i<n;i++){
        cin >> a >> b; a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(m);
    cout << risk+1 << endl << ans;
    return 0;
}
