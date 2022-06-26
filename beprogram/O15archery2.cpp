#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=5e5;
ll n, lw=LLONG_MAX, idx, ans=LLONG_MAX, qs[mxN], s=0;
ar<ll,2> a[mxN];
int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i][1];
        lw=min(lw,a[i][1]);
    }
    for(int i=0;i<n;i++)
        cin >> a[i][0];
    sort(a,a+n);
    qs[0]=a[0][1]; s=a[0][0];
    for(int i=1;i<n;i++){
        qs[i]=qs[i-1]+a[i][1];
        s+=a[i][0];
    }
    for(int i=0;i<n;i++){
        if(a[i][0]>lw)
            break;
        if(ans>s+qs[i-1]-n*a[i][0]){
            ans=s+qs[i-1]-n*a[i][0];
            idx=a[i][0];
        }
    }
    cout << idx << " " << ans;
    return 0;
}
