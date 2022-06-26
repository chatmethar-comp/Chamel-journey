#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=500, MOD=1e9+7;
int n, s;
ll dp[mxN*(mxN+1)/2];
int main()
{
    cin >> n;
    s=n*(n+1)/2;
    if(s%2){
        cout << 0;
        return 0;
    }
    s/=2;
    dp[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=i*(i+1)/2;j>=i;j--)
            dp[j]=(dp[j]+dp[j-i])%MOD;

    cout << dp[s]*((MOD+1)/2)%MOD;
    return 0;
}
