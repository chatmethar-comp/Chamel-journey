#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=15e3+5;
int n, k, ans=0;
ll x[mxN], y[mxN], d[mxN];
vector<ar<int,2>> edges;
int main()
{
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i];
        d[i]=0x3f3f3f;
    }
    d[0]=0;
    for(int i=1;i<n;i++){
        ll mx=0x3f3f3f, index=-1;
        for(int j=i;j<n;j++){
            d[j]=min(d[j],abs(x[j]-x[i-1])+abs(y[j]-y[i-1]));
            if(mx>d[j]){
                mx=d[j];
                index=j;
            }
        }
        swap(x[index],x[i]);
        swap(y[index],y[i]);
        swap(d[index],d[i]);
        for(int i=0;i<n;i++){
            cout << d[i] << " ";
        }
        cout << endl;
    }

    cout << endl;
    sort(d+1,d+n);
    for(int i=1;i<=n-k;i++)
        ans+=d[i];
    cout << ans;
    return 0;
}
/*
5 1
2 9
9 7
14 2
12 9
16 4
*/
