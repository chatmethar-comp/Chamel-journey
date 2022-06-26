#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=1e6+5;
ll dp[mxN];
ll minc(int n)
{
    if(n<=0)
        return 0;
    if(dp[n]==-1){
        ll mincost=INT_MAX;
        mincost=min(mincost,minc(n-15)+3000);
        mincost=min(mincost,minc(n-5)+1500);
        mincost=min(mincost,minc(n-2)+800);
        mincost=min(mincost,minc(n-1)+500);
        return dp[n]=mincost;
    }
    return dp[n];
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin >> n;
    cout << minc(n);
    return 0;
}
