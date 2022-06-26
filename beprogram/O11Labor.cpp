#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=1e6+5;
ll a[mxN];
int main()
{
    ios::sync_with_stdio(0);cin.tie(NULL);
    ll m, n, l, r, sum, mid;
    cin >> m >> n;
    for(int i=0;i<m;i++){
        cin >> a[i];
    }
    l=1;r=1e12;
    while(l<r){
        mid=(l+r)>>1;
        sum=0;
        for(int i=0;i<m;i++){
            sum+=(mid/a[i]);
        }
        if(sum>=n)
            r=mid;
        else
            l=mid+1;
//        cout << l << " " << mid << " " << r << endl;
    }
    cout << l << endl;
}
