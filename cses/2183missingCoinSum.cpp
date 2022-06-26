#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=2e5;
ll n, a[mxN], ans;
int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a,a+n);
    ans=1;
    for(int i=0;i<n&&a[i]<=ans;i++)
        ans+=a[i];
    cout << ans;
    return 0;
}
