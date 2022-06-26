#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=1e4;
int n, m, s, t, k;
vector<ar<ll,2>> adj[mxN];
priority_queue<ar<ll,2>, vector<ar<ll,2>>, greater<ar<ll,2>>> pq;
ll d1[mxN], d2[mxN];
int main()
{
    cin >> n >> m>> s >> t >> k;
    for(int i=0,x,y;i<m;i++){
        ll z;
        cin >> x >> y >> z;
        adj[x].push_back({z,y});
        adj[y].push_back({z,x});
    }
    memset(d1,0x3f,sizeof(d1));
    memset(d2,0x3f,sizeof(d2));
    d1[s]=0;d2[t]=0;
    pq.push({0,s});
    while(pq.size()){
        ar<ll,2> u=pq.top();
        pq.pop();
        if(d1[u[1]]<u[0])
            continue;
        for(ar<ll,2> v : adj[u[1]]){
            if(u[0]+v[0]<d1[v[1]]){
                d1[v[1]]=u[0]+v[0];
                pq.push({d1[v[1]],v[1]});
            }
        }
    }
    if(d1[t]<=k){
        cout << t << " " << d1[t] << " 0";
        return 0;
    }
    pq.push({0,t});
    while(pq.size()){
        ar<ll,2> u=pq.top();
        pq.pop();
        if(d2[u[1]]<u[0])
            continue;
        for(ar<ll,2> v : adj[u[1]]){
            if(u[0]+v[0]<d2[v[1]]){
                d2[v[1]]=u[0]+v[0];
                pq.push({d2[v[1]],v[1]});
            }
        }
    }
    ll d1i=0, idx=0;
    for(int i=0;i<n;i++){
        if(d1[i]<=k&&d1[i]>d1i){
            d1i=d1[i];
            idx=i;
        } else if(d1[i]==d1i&&d2[i]<d2[idx]){
            idx=i;
        }
    }
    cout << idx << " " << d1[idx] << " " << d2[idx];
    return 0;
}
