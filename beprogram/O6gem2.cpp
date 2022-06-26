#include<bits/stdc++.h>
using namespace std;
const int mxN=1e5, mxM=2e5;
int n, m;
int idx, p[mxM], a[2][mxM], val[mxM];
vector<int> adj[mxM], adjR[mxM];
bool vis[mxM], visR[mxM];
stack<int> st;

void dfsR(int u)
{
    visR[u]=1;
    for(int v : adjR[u])
        if(!visR[v])
            dfsR(v);
    st.push(u);
}

void scc(int u)
{
    vis[u]=1;
    val[u]=idx;
    for(int v : adj[u]){
        if(!vis[v])
            scc(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=5;
    while(t--){
        memset(vis, 0, sizeof(vis));
        memset(visR, 0, sizeof(visR));
        idx=0;
        cin >> n >> m;
        for(int i=0;i<n;i++){
            cin >> a[0][i] >> a[1][i];
        }
        for(int i=0,a,b;i<m/2;i++){
            cin >> a >> b;
            p[a]=b; p[b]=a;
        }
        for(int i=0;i<n;i++){
            adj[a[0][i]].push_back(p[a[1][i]]);
            adj[a[1][i]].push_back(p[a[0][i]]);
            adjR[p[a[0][i]]].push_back(a[1][i]);
            adjR[p[a[1][i]]].push_back(a[0][i]);
        }
        for(int i=1;i<=m;i++){
            if(!visR[i])
                dfsR(i);
        }
        while(st.size()){
            int u=st.top();

            st.pop();
            if(vis[u])
                continue;
            scc(u);
            idx++;
        }
        bool f=1;
        for(int i=1;i<=m;i++){
            if(val[i]==val[p[i]]){
                cout << "N";
                f=0;
                break;
            }
        }
        if(f)
            cout << "Y";
        for(int i=0;i<=m;i++){
            adj[i].clear();
            adjR[i].clear();
        }
    }
    return 0;
}
