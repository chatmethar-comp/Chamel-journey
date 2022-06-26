#include<bits/stdc++.h>
#define ll long long unsigned
using namespace std;
int main()
{
    int n, m;
    int l, k;
    int c;
    cin >> n >> m;
    cin >> l >> k;
    cin >> c;
    ll a, sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a;
            sum+=a;
        }
    }
    cout << (int)ceil((sum+(l*k*c))/(float)c) << endl;
    return 0;
}
