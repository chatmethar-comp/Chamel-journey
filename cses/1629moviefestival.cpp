#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=2e5;
ll n, mx=0, c=0;
ar<ll,2> a[mxN];
int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i][1] >> a[i][0];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(a[i][1]>=c){
            mx++;
            c=a[i][0];
        }
    }
    cout << mx;
    return 0;
}
