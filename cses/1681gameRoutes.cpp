#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=1e5, MOD=1e9+7;
int n, m, p[mxN];
vector<int> adj[mxN];
ll dp[mxN];
bool vis[mxN], act[mxN];

void dfs(int u)
{
    dp[u]=(u==n-1?1:0);
    vis[u]=1;
    act[u]=1;
    for(int v : adj[u]){
        if(act[v])
            continue;
        else{
            if(!vis[v]){
                p[v]=u;
                dfs(v);
            }
        }
        dp[u]=(dp[u]+dp[v])%MOD;
    }
    act[u]=0;
}

int main()
{
    cin >> n >> m;
    for(int i=0,a,b;i<m;i++){
        cin >> a >> b;a--,b--;
        adj[a].push_back(b);
    }
    for(int i=0;i<n;i++)
        if(!vis[i])
            dfs(i);

    cout << dp[0];
    return 0;
}
