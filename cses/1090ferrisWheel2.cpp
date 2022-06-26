#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=2e5;
ll n, x, p[mxN], ans=0, l, r;
int main()
{
    cin >> n >> x;
    for(int i=0;i<n;i++)
        cin >> p[i];
    sort(p,p+n);
    l=0, r=n-1;
    while(l<=r){
        if(p[l]+p[r]<=x)
            ans++,l++,r--;
        else
            ans++,r--;
    }
    cout << ans;
    return 0;
}
