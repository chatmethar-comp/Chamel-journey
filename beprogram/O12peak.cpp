#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxN=1e6+5;
int n, k, h[mxN];
int main()
{
    cin >> n >> k;
    for(ll i=0;i<n;i++)
        cin >> h[i];
    for(ll i=0;i<n;i++){
        cout << i << "  " << h[i] << " " << (int)(upper_bound(h,h+n,h[i])-h) << " " << (int)(lower_bound(h,h+n,h[i])-h) << endl;
    }

    return 0;
}
