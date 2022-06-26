#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=5010;
ll n, m;
ll dp[mxN];
bool vis[mxN], visR[mxN];
vector<ll> adj[mxN], adjR[mxN];
struct Edge{
    ll a;
    ll b;
    ll c;
}edges[mxN];

void dfs(ll u)
{
    vis[u]=1;
    for(ll v : adj[u])
        if(!vis[v])
            dfs(v);
}

void dfsR(ll u)
{
    visR[u]=1;
    for(ll v : adjR[u])
        if(!visR[v])
            dfsR(v);
}

int main()
{
    cin >> n >> m;
    for(ll i=0,a,b;i<m;i++){
        ll c;
        cin >> a >> b >> c;
        edges[i]={a,b,-c};
        adj[a].push_back(b);
        adjR[b].push_back(a);
    }
    dfs(1);
    dfsR(n);
    fill(dp+2,dp+n+1,0x3f3f3f3f3f3f3f3f);
    bool re=1;
    for(ll i=0;i<n&&re;i++){
        re=0;
        for(ll k=0;k<m;k++){
            ll u=edges[k].a;
            ll v=edges[k].b;
            ll w=edges[k].c;
            if(dp[v]>dp[u]+w){
                dp[v]=dp[u]+w;
                re=1;
                if(i==n-1&&vis[v]&&visR[v]){
                    cout << "-1\n";
                    return 0;
                }
            }
        }
    }
//    for(int i=0;i<n;i++){
//        cout << dp[i] <<" ";
//    }
//    cout << endl;
    cout << -dp[n];
    return 0;
}
