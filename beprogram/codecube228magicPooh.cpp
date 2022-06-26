#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ar array
const int mxN=1e5+5;
ll n, m, k, t, d[mxN];
vector<ar<ll,2>> adj[mxN];

int main()
{
    cin >> n >> m >> k >> t;
    for(int i=0;i<m;++i){
        int u, v, w;
        cin >> u >> v >> w;u--,v--;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    priority_queue<ar<ll,2>, vector<ar<ll,2>>, greater<ar<ll,2>>> pq;
    pq.push({0,0});
    memset(d, 0x3F, sizeof(d));
    d[0]=0;
    ll maxw=INT_MIN;
    while(pq.size()){
        ar<ll,2> u=pq.top();
        pq.pop();
        if(d[u[1]]<u[0]){
            continue;
        }
        for(ar<ll,2> v : adj[u[1]]){
            if(v[1]==n-1)
               maxw=max(maxw, v[0]);
            if(d[v[1]]>u[0]+v[0]){
                d[v[1]]=u[0]+v[0];
                pq.push({d[v[1]],v[1]});
            }
        }
    }
    ll ans=d[n-1]+k-maxw;
    if(ans<=t){
        cout << "Happy Winnie the Pooh :3\n" << ans;
    }else {
        cout << "No Honey TT";
    }
    return 0;
}
/*
Input
4 5 1 2
1 2 2
2 3 3
1 3 5
1 4 4
3 4 3
Output
Happy Winnie the Pooh :3
1
Happy Winnie the Pooh :3
1

No Honey TT
No Honey TT
*/
