#include<bits/stdc++.h>
using namespace std;
#define ar array
const int mxN=1e5+1, mxM=2e5+1;
stack<int> st;
vector<int> adj[mxM], adjR[mxM];
int val[mxM], idx;
bool vis[mxM];
int a[2][mxM],p[mxM];

void dfs(int u)
{
    if(vis[u])
        return;
    vis[u]=1;
    for(auto v : adj[u])
        dfs(v);
    st.push(u);
}

void scc(int u)
{
    if(vis[u])
        return;
    vis[u]=1;
    val[u]=idx;
    for(auto s : adjR[u])
        scc(s);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=5;
    while(t--){
        memset(val,0,sizeof(val));
        memset(vis,0,sizeof(vis));
        int n, m;
        idx=0;
        cin >> n >> m;
        for(int i=0;i<n;i++)
            cin >> a[0][i] >> a[1][i];
        for(int i=0,x,y;i<m/2;i++){
            cin >> x >> y;
            p[x]=y, p[y]=x;
        }
        for(int i=0;i<n;i++){
            adj[p[a[0][i]]].push_back(a[1][i]);
            adj[p[a[1][i]]].push_back(a[0][i]);
            adjR[a[1][i]].push_back(p[a[0][i]]);
            adjR[a[0][i]].push_back(p[a[1][i]]);
        }
        for(int i=1;i<=m;i++){
            if(!vis[i]){
                dfs(i);
            }
        }
        memset(vis,0,sizeof(vis));
        while(st.size()){
            int h=st.top();
            st.pop();
            if(vis[h])
                continue;
            scc(h);
            idx++;
        }
        bool pwl=1;
        for(int i=1;i<=m;i++){
            if(val[i]==val[p[i]]){
                cout << "N";
                pwl=0;
                break;
            }
        }
        if(pwl)
            cout << "Y";
        for(int i=0;i<=mxM;i++){
            adj[i].clear();
            adjR[i].clear();
        }
    }
    return 0;
}
