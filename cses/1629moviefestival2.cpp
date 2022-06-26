#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=2e5;
int n, c=0, l=0;
ar<ll,2> a[mxN];
int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i][1] >> a[i][0];
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(a[i][1]>=l){
            c++;
            l=a[i][0];
        }
    }
    cout << c;
    return 0;
}
