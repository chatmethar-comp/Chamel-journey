#include<bits/stdc++.h>
using namespace std;
#define ar array
int r, c, u, v, k, a[205][205];
bool vis[205][205];
char c;
int di[]={-1,0,1,0};
int dj[]={0,-1,0,1};
vector<ar<int,2>> adj[];
queue<ar<int,3>> qu;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> r >> c;
    for(int i=1;i<n*m;i++){
        cin >> u >> c >> v;
        if(c=='L'){
            adj[u].push_back({v,1});
            adj[v].push_back({u,3});
        }
        if(c=='U'){
            adj[u].push_back({v,2});
            adj[v].push_back({u,0});
        }
    }
    for(int i=0;i<n*m;i++){
        memset(a,-1,sizeof(a));
        memset(vis,0,sizeof(vis));
        qu.push({i,1,1});
        a[1][1]=i;
        bool ch=0;
        while(qu.size()){
            u=qu.front()[1];
            v=qu.front()[2];
            k=qu.front()[0];
            qu.pop();
            if(vis[u][v])
                continue;
            vis[u][v]=1;
            for(ar<int,2> i)
        }
    }
    return 0;
}
