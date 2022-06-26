#include<bits/stdc++.h>
using namespace std;
#define ar array
const int mxN=3e3;
int n, m, u, v, w, p[mxN];
int st, en, a, ans;
vector<pair<int,ar<int,2>>> edge;

int Find(int i)
{
    if(p[i]==i)
        return i;
    return p[i]=Find(p[i]);
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> u >> v >> w;
        edge.push_back({w,{u,v}});
    }
    cin >> st >> en >> a;
    iota(p+1,p+n+1,1);
    sort(edge.begin(),edge.end(),greater<>());
    for(auto c : edge){
        int pu=Find(c.second[0]), pv=Find(c.second[1]);
        if(pu!=pv){
            p[pv]=pu;
        }
        if(Find(st)==Find(en)){
            ans=c.first;
            break;
        }
    }
    ans--;
    cout << (a+ans+1)/ans;
    return 0;
}
