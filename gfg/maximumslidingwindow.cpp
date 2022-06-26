#include<bits/stdc++.h>
using namespace std;
#define ar array
const int mxN=2e5+5;
int n, m, ti=1, vis[mxN], l[mxN], fb[mxN];
pair<int,int> g[mxN];
vector<int> adj[mxN];
bitset<mxN> inst;
stack<int> st;

void dfs(int i)
{
    vis[i]=ti,l[i]=ti;
    ti++;
    st.push(i);
    cout << i << " ";
    inst[i]=1;
    for(int u : adj[i]){
//        cout << i << " " << u << " visi: " <<vis[i] << " ti: " << ti << " li: " << l[i] << endl;
        if(!vis[u]){
            dfs(u);
            l[i]=min(l[i],l[u]);
        } else if(inst[i]){
            l[i]=min(l[i],l[u]);
        }
    }
    if(vis[i]==l[i]){
        while(st.top()!=i){
            inst[st.top()]=0;
            st.pop();
        }
        inst[st.top()]=0;
        st.pop();
    }
}

void play()
{
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=mxN;i++){
        adj[i].clear();
    }
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> g[i].first >> g[i].second;
    }
    for(int i=0, a, b;i<m/2;i++){
        cin >> a >> b;
        fb[a]=b;
        fb[b]=a;
    }
    for(int i=1;i<=n;i++){
        adj[fb[g[i].first]].push_back(g[i].second);
        adj[fb[g[i].second]].push_back(g[i].first);
    }
    bool ch=1;
    for(int i=1;i<=m;i++){
        if(!vis[i])
            dfs(i);
        cout << endl;
    }
    for(int i=1;i<=m;i++){
        if(l[i]==l[fb[i]]){
            ch=0;
            break;
        }
    }
    if(ch)
        cout << "Y";
    else
        cout << "N";

}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    play();
    return 0;
}

/*
4 6
2 3 6 5 3 4 1 2
1 3 2 5 4 6
Y
*/
