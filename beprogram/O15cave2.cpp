#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=2e3;
ll n, st, en, e, d[mxN][mxN];
vector<ar<ll,2>> adj[mxN];
priority_queue<ar<ll,3>, vector<ar<ll,3>>, greater<ar<ll,3>>> pq;
int main()
{
    cin >> n >> st >> en >> e;
    for(int i=0;i<e;i++){
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    memset(d,0x3f,sizeof(d));
    d[st][0]=0;
    pq.push({0,st,0});
    while(pq.size()){
        ar<ll,3> u=pq.top();
        pq.pop();
        for(ar<ll,2> v : adj[u[1]]){
            if(d[v[1]][u[2]]>u[0]+v[0]){
                d[v[1]][u[2]]=u[0]+v[0];
                pq.push({d[v[1]][u[2]],v[1],u[2]+1});
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << i << " - ";
        for(int j=0;j<n;j++){
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
//    cin >> t;
//    while(t--){
//        cin >> h;
//    }
    return 0;
}
