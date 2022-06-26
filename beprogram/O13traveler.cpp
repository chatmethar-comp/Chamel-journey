#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=1e5;
ll n, m, st, en, x;
vector<ar<ll,2>> adj[mxN];
priority_queue<ar<ll,2>, vector<ar<ll,2>>, greater<ar<ll,2>>> pq;
ll d1[mxN], d2[mxN];
int main()
{
    cin >> n >> m;
    cin >> st >> en >> x;
    for(int i=0;i<m;i++){
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    memset(d1,0x3f,sizeof(d1));memset(d2,0x3f,sizeof(d2));
    d1[st]=0;d2[en]=0;
    pq.push({0,st});
    while(pq.size()){
        ar<ll,2> u=pq.top();
        pq.pop();
        if(d1[u[1]]<u[0])
            continue;
        for(ar<ll,2> v : adj[u[1]]){
            if(d1[v[1]]>u[0]+v[0]){
                d1[v[1]]=u[0]+v[0];
                pq.push({d1[v[1]],v[1]});
            }
        }
    }
//    for(int i=0;i<n;i++){
//        cout << i << " " << d1[i] << endl;
//    }
    if(d1[en]<=x){
        cout << en << " " << d1[en] << " 0";
        return 0;
    }
    pq.push({0,en});
    while(pq.size()){
        ar<ll,2> u=pq.top();
        pq.pop();
        if(d2[u[1]]<u[0])
            continue;
        for(ar<ll,2> v : adj[u[1]]){
            if(d2[v[1]]>u[0]+v[0]){
                d2[v[1]]=u[0]+v[0];
                pq.push({d2[v[1]],v[1]});
            }
        }
    }
    ll mx=0, id;
    for(int i=0;i<n;i++){
        if(d1[i]!=0&&d1[i]<=x&&d1[i]>mx){
            mx=d1[i]; id=i;
        }
    }
    cout << id << " " << mx << " " << d2[id];
    return 0;
}
