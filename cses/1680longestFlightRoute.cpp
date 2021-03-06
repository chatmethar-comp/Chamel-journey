#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=1e5;
int n, m, p[mxN];
vector<int> adj[mxN], ans;
bool vis[mxN], act[mxN];
ll dp[mxN];

void dfs(int u)
{
    dp[u]=(u==n-1?1:-1e9);
    vis[u]=1;
    act[u]=1;
    for(int v : adj[u]){
        if(act[v]){
            cout << "IMPOSSIBLE";
            exit(0);
        } else {
            if(!vis[v]){
                p[v]=u;
                dfs(v);
            }
        }
        if(dp[v]+1>dp[u]){
            p[u]=v;
            dp[u]=dp[v]+1;
        }
    }
    act[u]=0;
}

int main()
{
    cin >> n >> m;
    for(int i=0,a,b;i<m;i++){
        cin >> a >> b; a--, b--;
        adj[a].push_back(b);
    }
    for(int i=0;i<n;i++)
        if(!vis[i])
            dfs(i);
    if(dp[0]<0){
        cout << "IMPOSSIBLE";
    }
    else {
        int u=0;
        ans.push_back(u);
        while(u!=n-1){
            u=p[u];
            ans.push_back(u);
        }
        cout << ans.size() << endl;
        for(int a : ans){
            cout << a+1 << " ";
        }
    }

    return 0;
}
