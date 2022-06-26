#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=2e5;
ll n, x, l, r, i1, i2;
ar<ll,2> a[mxN];
int main()
{
    cin >> n >> x;
    for(int i=0;i<n;i++){
        cin >> a[i][0];
        a[i][1]=i;
    }
    sort(a,a+n);
    l=0, r=n-1;
    while(l<r){
        if(a[l][0]+a[r][0]==x){
            i1=a[l][1],i2=a[r][1];
            i1++;i2++;
            cout << i1 << " " << i2;
            return 0;
        }
        if(a[l][0]+a[r][0]>x)
            r--;
        else
            l++;
    }
    cout << "IMPOSSIBLE";
    return 0;
}
