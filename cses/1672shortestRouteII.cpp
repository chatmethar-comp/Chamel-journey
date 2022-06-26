#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=500;
ll n, m, q;
vector<ar<int,2>> adj[mxN];
ll d[mxN][mxN];
int main()
{
    memset(d,0x3f,sizeof(d));
    cin >> n >> m >> q;
    for(ll i=0,a,b,c;i<m;i++){
        cin >> a >> b >> c;a--;b--;
        d[a][b]=min(d[a][b],c);
        d[b][a]=min(d[b][a],c);
    }
    for(int i=0;i<n;++i)
        d[i][i]=0;
    for(ll k=0;k<n;++k)
        for(ll i=0;i<n;++i)
            for(ll j=0;j<n;++j)
            d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    while(q--){
        int a, b;
        cin >> a >> b;a--;b--;
        cout << (d[a][b]>=1e18?-1:d[a][b]) << endl;
    }
    return 0;
}
