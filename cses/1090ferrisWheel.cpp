#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxN=2e5;
ll n, x, p[mxN];

int main()
{
    cin >> n >> x;
    for(int i=0;i<n;++i){
        cin >> p[i];
    }
    sort(p, p+n);
    int ans=0;
    for(int i=0, j=n-1;i<j;){
        while(i<j&&p[i]+p[j]>x){
            j--;
        }
        if(i>=j)
            break;
        ++ans;
        ++i, --j;
    }
    cout << n-ans;
    return 0;
}
