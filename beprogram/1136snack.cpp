#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=1e6+5;
int a, b, ans=0, na, nb;
double m, n, k;
vector<double> A, B;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> a >> b;
    for(int i=0;i<a;i++){
        cin >> k;
        m+=k;
        A.push_back(k);
    }
    for(int i=0;i<b;i++){
        cin >> k;
        n+=k;
        B.push_back(k);
    }
    m=m/a;n=n/b;
    // make m is always greater that n;
    if(m>n){
        swap(m,n);
        swap(a,b);
        swap(A,B);
    }
    na=a, nb=b;
    for(int i=0;i<b;i++){
        if(B[i]<n&&B[i]>m&&nb>1){
            m=(na*m+B[i])/(na+1);
            n=(nb*n-B[i])/(nb-1);
            ans++;
            na++;
            nb--;
        }
    }
    cout << ans;
    return 0;
}
