// 15/100
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=15e3+5;
ll e, t, x, y, ans=0;
ll p[mxN];
ll vis[mxN];
vector<ar<ll,3>> edges;
vector<ar<ll,2>> h;
ll cp()
{
    set<ll> s;
    ll c=0;
    for(int i=0;i<e;i++){
        if(s.find(p[i])==s.end()){
            s.insert(p[i]);
            c++;
        }
    }
    return c;
}

ll Find(int i)
{
    memset(vis, 0, sizeof(vis));
    if(p[i]==i){
        return i;
    }
    return p[i]=Find(p[i]);
}

int main()
{
    cin >> e >> t;
    for(ll i=0;i<e;i++){
        cin >> x >> y;
        h.push_back({x,y});
        p[i]=i;
    }
    for(ll i=0;i<h.size();i++){
        for(ll j=i+1;j<h.size();j++){
            edges.push_back({abs(h[i][0]-h[j][0])+abs(h[i][1]-h[j][1]),i,j});
        }
    }
    sort(edges.begin(),edges.end());
    for(auto [w,i,j] : edges){
        if(vis[i]>=2||vis[j]>=2)
            continue;
        ll pu=Find(i), pv=Find(j);
        if(pu==pv)
            continue;
        p[pv]=pu;
        vis[i]++;vis[j]++;
//
        if(cp()==t)
            break;
        ans+=w;
        cout << ans << " ";

//        cout << ans << " " << cp() << endl;;

    }
    cout <<endl << endl;
    for(int i=0;i<e;i++){
        cout << p[i] << " ";
    }
    cout << ans;
    return 0;
}

/*
5 1
2 9
9 7
14 2
12 9
16 4
*/
