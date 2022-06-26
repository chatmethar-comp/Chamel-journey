#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=1e5;
int n, m;
ll ans=1e15;
vector<ar<ll,2>> adj1[mxN], adj2[mxN];
ll d1[mxN], d2[mxN];
priority_queue<ar<ll,2>, vector<ar<ll,2>>, greater<ar<ll,2>>> pq;
ll es[mxN];
int main()
{
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b; ll c;
        cin >> a >> b >> c; a--, b--;
        adj1[a].push_back({c,b});
        adj2[b].push_back({c,a});
    }
    memset(d1,0x3f,sizeof(d1));
    memset(d2,0x3f,sizeof(d2));
    d1[0]=0;
    d2[n-1]=0;
    pq.push({0,0});
    while(pq.size()){
        ar<ll,2> u=pq.top();
        pq.pop();
        if(d1[u[1]]<u[0])
            continue;
        for(ar<ll,2> v : adj1[u[1]]){
            if(u[0]+v[0]<d1[v[1]]){
                d1[v[1]]=u[0]+v[0];
                pq.push({d1[v[1]],v[1]});
            }
        }
    }
    pq.push({0,n-1});
    while(pq.size()){
        ar<ll,2> u=pq.top();
        pq.pop();
        if(d2[u[1]]<u[0])
            continue;
        for(ar<ll,2> v : adj2[u[1]]){
            if(u[0]+v[0]<d2[v[1]]){
                d2[v[1]]=u[0]+v[0];
                pq.push({d2[v[1]],v[1]});
            }
        }
    }
    for(int i=0;i<n;i++){
        for(ar<ll,2> j : adj1[i])
            ans=min(ans,d1[i]+d2[j[1]]+j[0]/2);
    }
    cout << ans;
    return 0;
}
