#include<bits/stdc++.h>
using namespace std;
const int mxN=1e9+5;
int n, q, p[100005], t, qs[100005];
int main()
{
    qs[0]=0;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> p[i];
        qs[i]=qs[i-1]+p[i];
    }
    while(q--){
        cin >> t;
        cout << (int)(upper_bound(qs,qs+n,t)-qs)-1 << endl;
    }
    return 0;
}
