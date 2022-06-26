#include<bits/stdc++.h>
using namespace std;
stack<int> st;
int val[200001],idx;
bool vis[200001];
vector<int> adj[200001],rev[200001];
void dfs(int i){
    if (vis[i]) return;
    vis[i] = true;
    for (auto s : adj[i]) dfs(s);
    st.push(i);
}
void scc(int x) {
    if (vis[x]) return;
    vis[x]=true;
    val[x]=idx;
    for (auto s : rev[x]) scc(s);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=1; i<=5; ++i) {
        int n,m;
        int a[2][200001],p[200001];
        memset(vis,0,sizeof(vis));
        memset(val,0,sizeof(val));
        idx=0;
        cin>>n>>m;
        for (int i=0; i<n; ++i) cin>>a[0][i]>>a[1][i];
        for (int i=0; i<m/2; ++i) {
            int a,b;
            cin>>a>>b;
            p[a]=b;
            p[b]=a;
        }
        for (int i=0; i<n; ++i) {
            adj[p[a[0][i]]].push_back(a[1][i]);
            adj[p[a[1][i]]].push_back(a[0][i]);
            rev[a[1][i]].push_back(p[a[0][i]]);
            rev[a[0][i]].push_back(p[a[1][i]]);
        }
        for (int i=1; i<=m; ++i) {
            if (!vis[i]) {
                dfs(i);
            }
        }
        memset(vis,0,sizeof(vis));
        while (!st.empty()) {
            int h=st.top();
            st.pop();
            if (vis[h]) continue;
            scc(h);
            ++idx;
        }
        bool kk=true;
        for (int i=1; i<=m; ++i) {
            if (val[i]==val[p[i]]) {
                cout<<"N";
                kk=false;
                break;
            }
        }
        if (kk) cout<<"Y";
        for (int i=0; i<=200001; ++i) {
            rev[i].clear(); adj[i].clear();
        }
    }
}

