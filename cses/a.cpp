#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=5e3;
int n, m;
ll dp[mxN];
bool vis[mxN], visR[mxN], re=1;
vector<int> adj[mxN], adjR[mxN];
ar<ll,3> edges[mxN];

void dfs(int u)
{
    vis[u]=1;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v);
}

void dfsR(int u)
{
    visR[u]=1;
    for(int v : adjR[u])
        if(!visR[v])
            dfsR(v);
}

int main()
{
    cin >> n >> m;
    for(int i=0,a,b;i<m;i++){
        ll c;
        cin >> a >> b >> c;a--, b--;
        adj[a].push_back(b);
        adjR[b].push_back(a);
        edges[i]={a,b,-c};
    }
    dfs(0);
    dfsR(n-1);
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int k=0;k<n&&re;k++){
        re=0;
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            ll w=edges[i][2];
            if(dp[u]+w<dp[v]){
                dp[v]=dp[u]+w;
                re=1;
                if(k==n-1&&vis[v]&&visR[v]){
                    cout << "-1";
                    return 0;
                }
            }
        }
    }
    cout << -dp[n-1];
    return 0;
}
