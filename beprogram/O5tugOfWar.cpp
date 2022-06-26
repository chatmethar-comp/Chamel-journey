#include<bits/stdc++.h>
using namespace std;
int a[2100], b[2100], ans=0;
int main()
{
    int i, n;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    for(i=0;i<n;i++){
        cin >> b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    for(i=0;i<n;i++)
        ans+=abs(a[i]-b[i]);
    cout << ans;
    return 0;
}
