#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=1e5+1, mxK=1e4+1;
int n, k, t, ans=-1, used, vis[mxN];
vector<int> adj[mxN], p[mxK];

void dfs(int u)
{
    if(vis[u]==2)
        return;
    if(vis[u]==1){
        used=mxN;
        return;
    }
    if(vis[u]==0){
        vis[u]=1;
        for(int v : adj[u])
            dfs(v);
    }
    vis[u]=2;
    used++;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k >> t;
    for(int i=1,l,a;i<=n;i++){
        cin >> l >> a;
        p[l].push_back(i);
        for(int j=0,x;j<a;j++){
            cin >> x;
            adj[i].push_back(x);
        }
    }
    for(int i=1;i<=k;i++){
        for(int v : p[i])
            dfs(v);
        if(used>t)
            break;
        ans=i;
    }
    cout << ans;
    return 0;
}
