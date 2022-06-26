#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=2e5;
ll n, a, ans=-1e18, msf=-1e18;
int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        msf=max(a,msf+a);
        ans=max(ans,msf);
    }
    cout << ans << endl;
    return 0;
}
