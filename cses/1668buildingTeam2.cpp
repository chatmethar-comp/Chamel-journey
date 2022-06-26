#include<bits/stdc++.h>
using namespace std;
const int mxN=1e5;
int n, m, a, b;
bool possible, vis[mxN], team[mxN];
vector<int> adj[mxN];
// bfs?
void dfs(int u, int p=0)
{
    for(int v : adj[u]){
        if(v!=p){
            if(!vis[v]){
                team[v]=!team[u];
                vis[v]=1;
                dfs(v,u);
            } else if(team[v]==team[u])
                cout << "IMPOSSIBLE",exit(0);
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i=0;i<m;++i){
        cin >> a >> b;--a,--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    possible=true;
    for(int i=0;i<n;++i){
        if(!vis[i])
            vis[i]=true,dfs(i);
    }
    for(int i=0;i<n;++i)
        cout << team[i]+1 << " ";
    return 0;
}
