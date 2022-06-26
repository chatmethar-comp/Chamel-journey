#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=2e5;
ll n, p[mxN], ans=0;
int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> p[i];
    sort(p,p+n);
    for(int i=0;i<n;i++)
        ans+=abs(p[i]-p[n/2]);
    cout << ans;
    return 0;
}
