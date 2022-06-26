// 0/100
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
long long station[500005];
queue<pll> q;

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<pair<long long,long long>> adj[n];
    // { cost ,{ from , to } }
    for(long long i=0;i<n;i++){
        cin >> station[i];
    }
    for(long long i=0;i<n;i++){
        for(long long j=1;j<=k;j++){
            if(i+j>=n){
                continue;
            }
            adj[i].push_back({station[i+j], i+j});
        }
    }
    pll state;
    q.push({station[0],0});
    ll mincost = INT_MAX;
    while(!q.empty()){
        state = q.front();
        cout << state.first << " " << state.second << endl;
        if(state.second==n-1){
            mincost = min(mincost, state.first);
        }
        q.pop();
        for(pll next : adj[state.second]){
            if(next.first+state.first<mincost)
                q.push({next.first+state.first, next.second});
        }
    }
    cout << mincost<< endl;
//    for(long long i=0;i<n;i++){
//        cout << i;
//        for(pair<long long, long long> edge : adj[i]){
//            cout << " -> " << edge.first << " " << edge.second;
//        }
//        cout << endl;
//    }

    return 0;
}
