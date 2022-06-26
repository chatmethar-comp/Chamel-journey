#include<bits/stdc++.h>
using namespace std;
int n, c;
string edge;
vector<int> adj[30], ans;
bool vis[305];
void dfs(int n)
{
    c++;
    vis[n]=1;
    ans.push_back(n);
    for(int i : adj[n])
        if(!vis[i])
            dfs(i);
}

int main()
{

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> edge;
        adj[edge[0]-'A'].push_back(edge[1]-'A');
        adj[edge[1]-'A'].push_back(edge[0]-'A');
    }
    for(int i=0;i<26;i++){
        memset(vis,0,sizeof(vis));
        c=0;
        dfs(i);

    }
    return 0;
}
