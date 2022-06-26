#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=2.5e3+1,mxM=5e3+1;
int n, m, re=-1, p[mxN];
ll d[mxN];

struct edge{
    int a, b;
    ll c;
}edges[mxM];

int main()
{
    cin >> n >> m;
    for(int i=0,a,b;i<m;i++){
        ll c;
        cin >> a >> b >> c;
        edges[i]={a,b,c};
    }
    memset(d,0x3f,sizeof(d));
    d[1]=0;
    for(int k=0;k<n&&re;k++){
        re=0;
        for(int i=0;i<m;i++){
            int u=edges[i].a;
            int v=edges[i].b;
            ll w=edges[i].c;
            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                p[v]=u;
                re=v;
            }
        }
    }
    if(!re){
        cout << "NO";
        return 0;
    }
    for(int i=0;i<n;i++)
        re=p[re];
    vector<int> ans;
    for(int v=re;;v=p[v]){
        ans.push_back(v);
        if(v==re&&ans.size()>1)
            break;
    }
    reverse(ans.begin(),ans.end());
    cout << "YES\n";
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << " ";
    return 0;
}
