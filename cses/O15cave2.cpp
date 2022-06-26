#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=2e3+5;
ll n, st, en, e, l, h;
vector<pair<ll,ll>> adj[mxN];
priority_queue<pair<ll,pair<ll,ll>>, vector<pair<ll,pair<ll,ll>>>, greater<pair<ll,pair<ll,ll>>>> pq;
ll d[mxN][mxN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(d,0x3f3f3f,sizeof(d));
    cin >> n >> st >> en >> e;
    for(ll i=0,a,b,c;i<e;i++){
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
    }
    d[st][0]=0;
    pq.push({0,{st,-1}});
    while(pq.size()){
        ll dist=pq.top().first;
        ll u=pq.top().second.first;
        ll step=pq.top().second.second;
        pq.pop();
        if(d[u][step]<dist)
            continue;
        for(pair<ll,ll> v : adj[u]){
            ll ns=step+1;
            if(d[v.second][ns]>d[u][step]+v.first){
                d[v.second][ns]=d[u][step]+v.first;
                pq.push({d[v.second][ns],{v.second,ns}});
            }
        }
    }
//    for(int i=0;i<=n;i++){
//        for(int j=0;j<=n;j++){
//            cout << d[i][j] << " ";
//        }
//        cout << endl;
//    }
    cin >> l;
    while(l--){
        cin >> h;
        ll ans=0x3f3f3f;
        for(int i=0;i<=n;i++){
            if(d[en][i]!=0x3f3f3f)
                ans=min(ans,d[en][i]+h*i);
        }
        cout << ans << " ";
    }

    return 0;
}
