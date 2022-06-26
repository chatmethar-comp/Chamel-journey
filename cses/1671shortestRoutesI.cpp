#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mxN=1e5;
int n, m;
vector<array<ll, 2>> adj[mxN];
ll d[mxN];

 int main()
 {
     cin >> n >> m;
     for(int i=0, a, b, c;i<m;i++){
        cin >> a >> b >> c;a--,b--;
        adj[a].push_back({c, b});
//        adj[b].push_back({c, a});
     }
     priority_queue<array<ll,2>, vector<array<ll,2>>, greater<array<ll,2>>> pq;
     pq.push({0,0});
     memset(d, 0x3F, sizeof(d));
     d[0]=0;
     while(pq.size()){
        array<ll, 2> u=pq.top();
        pq.pop();
        if(u[0]>d[u[1]]){
            continue;
        }
        for(array<ll, 2> v: adj[u[1]]){
            if(d[v[1]]>v[0]+u[0]){
                d[v[1]]=v[0]+u[0];
                pq.push({d[v[1]],v[1]});
            }
        }
     }
     for(int i=0;i<n;++i){
        cout << d[i] << " ";
     }
 }
