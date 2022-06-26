#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=1e5+1;
int n, q, a[mxN], l, m, r;
ll ans, qs[mxN];
int main()
{
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        qs[i]=qs[i-1]+a[i];
    }
    while(q--){
        ans=0;
        cin >> l >> m >> r;
        if(m==1){
            cout << qs[r]-qs[l-1] << " ";
            continue;
        }
        if(l+m>r){
            cout << a[l] << " ";
            continue;
        }
        for(int i=l;i<=r;i+=m)
            ans+=a[i];
        cout << ans << " ";
    }
    return 0;
}
