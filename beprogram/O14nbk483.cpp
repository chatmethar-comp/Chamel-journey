#include<bits/stdc++.h>
using namespace std;
#define ar array
const int mxN=1e5+1;
int n, m, x, num[mxN];
ar<int,2> d[mxN];
int main()
{
    cin >> n >> m;
    for(int i=1, a;i<=n;i++){
        cin >> a;
        d[i]={d[i-1][0]+a,i};
    }
    sort(d+1,d+n+1);
    for(int i=1;i<=n;i++){
        num[i]=d[i][0];
        d[i][1]=max(d[i-1][1],d[i][1]);
    }
    while(m--){
        cin >> x;
        int u=upper_bound(num+1,num+n+1,x)-(num+1);
        cout << d[u][1] << endl;
    }
    return 0;
}
