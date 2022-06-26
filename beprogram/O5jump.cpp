#include<bits/stdc++.h>
using namespace std;
int n, k, a[30100], mx=0;
int main()
{
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        mx=max(mx,(int)(upper_bound(a,a+n,a[i]+k)-a)-i-1);
    }
    cout << mx;
    return 0;
}
