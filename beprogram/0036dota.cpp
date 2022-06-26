#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fac(int s,int n)
{
    ll res=1;
    for(int i=s;i<=n;i++){
        res *= i;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    if(n%2){
        n++;
    }
    cout << fac(n/2 +1,n)/fac(1,n/2) << endl;
    return 0;
}
