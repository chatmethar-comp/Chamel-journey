#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=1e6+5;
int n;
ll x, c[105], dp[mxN];
int main()
{
    memset(dp,0x3f3f3f,sizeof(dp));
    dp[0]=0;
    cin >> n >> x;
    for(int i=0;i<n;i++){
        cin >> c[i];
    }
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i-c[j]>=0){
                dp[i]=min(dp[i],dp[i-c[j]]+1);
            }
        }
    }
//    for(int i=0;i<x;i++)
//        cout << dp[i] << " ";
//    cout << endl;
    if(dp[x]>=0x3f3f3f)
        cout << "-1";
    else
        cout << dp[x];
    return 0;
}
