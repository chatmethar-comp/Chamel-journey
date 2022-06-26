#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=1e2;
ll n, m, c[mxN], st, en, cp;
vector<ar<ll,2>> adj[mxN];
priority_queue<ar<ll,2>, vector<ar<ll,2>>, greater<ar<ll,2>>> pq;
ll d[mxN];
int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> c[i];
    cin >> st >> en >> cp;
    cin >> m;
    for(int i=0;i<m;i++){
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w*c[u],v});
        adj[v].push_back({w*c[v],u});
    }
    memset(d,0x3f,sizeof(d));
    d[st]=0;
    pq.push({0,st});
    while(pq.size()){
        ar<ll,2> u=pq.top();
        pq.pop();
        if(d[u[1]]<u[0])
            continue;
        for(ar<ll,2>)
    }
    return 0;
}
