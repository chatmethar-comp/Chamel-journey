#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=2e5;
ll n, m, k, a[mxN], b[mxN], j=0, ans=0;

int main()
{
    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<m;i++)
        cin >> b[i];
    sort(a,a+n);
    sort(b,b+m);
    for(int i=0;i<n;i++){
        while(j<m&&b[j]<a[i]-k)
            j++;
        if(j<m&&b[j]<=a[i]+k)
            j++,ans++;
    }
    cout << ans;
    return 0;
}
