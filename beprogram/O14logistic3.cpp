#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=101;
int dist[mxN][mxN];
priority_queue<ar<ll,3>, vector<ar<ll,3>>, greater<ar<ll,3>>> pq; // w, u, f
vector<ar<int,2>> adj[mxN];
int n, a[mxN], s, e, d, m;
int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cin >> s >> e >> d >> m;
    while(m--){
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    memset(dist,0x3f,sizeof(dist));
    pq.push({0,s,0});
    while(pq.size()){
        ar<ll,3> u=pq.top();
        pq.pop();
        if(u[2]+1<=d&&u[0]+a[u[1]]<dist[u[1]][u[2]]){

            pq.push();
        }
    }
    return 0;
}
