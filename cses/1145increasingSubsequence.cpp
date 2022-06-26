#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=2e5;
int n, lis=0;
ll x, d[mxN];
int main()
{
    cin >> n;
    memset(d,0x3f,sizeof(d));
    for(int i=0;i<n;i++){
        cin >> x;
        int index=lower_bound(d,d+lis,x)-d;
        if(d[index]>x)
            d[index]=x;
        if(index==lis)
            lis++;
    }
    cout << lis;
    return 0;
}
