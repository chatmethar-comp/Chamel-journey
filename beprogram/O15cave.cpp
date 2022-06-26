#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> ii;
typedef pair<ll,ii> pii;
ll n, st, en, e, l, h, ans;
ll d[2005][2005];
vector<ii> adj[2005];
bool vis[2005][2005];
priority_queue<pii,vector<pii>,greater<pii>> pq;
int main()
{
    cin >> n >> st >> en >> e;
    for(ll i=0;i<=n;i++)
        for(ll j=0;j<=n;j++)
            d[i][j]=LLONG_MAX;
    for(ll i=0,a,b,c;i<e;i++){
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
    }
    d[st][0]=0;
    pq.push({0,{st,0}});
    while(pq.size()){
        ll dist=pq.top().first;
        ll u=pq.top().second.first;
        ll step=pq.top().second.second;
        pq.pop();
        if(d[u][step]<dist || vis[u][step])
            continue;
        vis[u][step]=1;
        for(auto [w,v] : adj[u]){
            ll nstep=(u==st?step:step+1);
            if(d[v][nstep]>d[u][step]+w){
                d[v][nstep]=d[u][step]+w;
                pq.push({d[v][nstep],{v,nstep}});
            }
        }
    }
    cin >> l;
    while(l--){
        cin >>h;
        ans=LLONG_MAX;
        for(ll i=0;i<n;i++)
            if(d[en][i]<ans)
                ans=min(ans,d[en][i]+h*i);
        cout << ans << " ";
    }
    return 0;
}
