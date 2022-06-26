#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=1e5;
int n, m, k;
vector<ar<ll,2>> adj[mxN];
vector<ll> ans[mxN];
priority_queue<ar<ll,2>, vector<ar<ll,2>>, greater<ar<ll,2>>> pq;
ll d[mxN];
int main()
{
    cin >> n >> m >> k;
    for(int i=0,a,b;i<m;i++){
        ll c;
        cin >> a >> b >> c;a--,b--;
        adj[a].push_back({c,b});
    }
    memset(d,0x3f,sizeof(d));
    d[0]=0;
    pq.push({0,0});
    while(pq.size()){
        ar<ll,2> u=pq.top();
        pq.pop();

        if(d[u[1]]<u[0])
            continue;
        for(ar<ll,2> v : adj[u[1]]){

            if(u[0]+v[0]<d[v[1]]){
                d[v[1]]=u[0]+v[0];
                ans[v[1]].push_back(d[v[1]]);
                pq.push({d[v[1]],v[1]});
            }

        }
    }
    sort(ans[n-1].begin(),ans[n-1].end());
    for(int i=0;i<k;i++)
        cout << ans[n-1][i] << " ";
    return 0;
}
