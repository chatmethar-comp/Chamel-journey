#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=1e6+5;
struct A{
    int u, v, w;
    bool operator<(const A&o)const{
        return w > o.w;
    }
};
A a[mxN];
int p[200010], n, m;
ll ans=0;
int Find(int i)
{
    if(p[i]==i)
        return i;
    return p[i]=Find(p[i]);
}
int main()
{
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a[i].u >> a[i].v >> a[i].w;
        a[i].w--;
    }
    sort(a,a+m);
    iota(p+1,p+n+1,1);
    for(int i=0;i<m;i++){
        int u, v;
        u=Find(a[i].u);v=Find(a[i].v);
        if(u==v)
            continue;
        ans+=a[i].w;
        p[u]=v;
    }
    cout << ans;
    return 0;
}
