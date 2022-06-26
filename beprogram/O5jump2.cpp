#include<bits/stdc++.h>
using namespace std;
int n, k, dp[90100], a[30100], mx=0;
int main()
{
    memset(dp,0,sizeof(dp));
    cin >> n >> k;
    for(int i=0;i<n;++i){
        cin >> a[i];
        dp[a[i]]=1;
    }
    for(int i=0;i<a[n-1]+k;i++){
        dp[i]+=dp[i-1];
    }
    for(int i=0;i<n;++i){
        mx=max(mx,dp[a[i]+k]-dp[a[i]]);
    }
    cout << mx;
    return 0;
}
