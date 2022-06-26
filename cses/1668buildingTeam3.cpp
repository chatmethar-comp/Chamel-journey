#include<bits/stdc++.h>
using namespace std;
const int mxN=1e5;
int n, m, p[mxN];
vector<int> adj[mxN];
bool vis[mxN];

void dfs(int u)
{
    vis[u]=1;
    for(int v :adj[u]){
        if(p[v]==p[u]&&p[v]!=0){
            cout << "IMPOSSIBLE";
            exit(0);
        }
        if(!vis[v]){
            p[v]=!p[u];
            dfs(v);
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i=0,a,b;i<m;i++){
        cin >> a >> b; a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        if(!vis[i])
            dfs(i);
    }
    for(int i=0;i<n;i++){
        cout << p[i]+1 << " ";
    }
    return 0;
}
