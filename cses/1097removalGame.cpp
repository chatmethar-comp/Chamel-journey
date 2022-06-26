#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=5e3;
int n, x[mxN];
ar<ll,2> dp[mxN][mxN];
int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> x[i];
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            ar<ll,2> t;
            if(dp[i+1][j][1]+x[i]>dp[i][j-1][1]+x[j])
                t={dp[i+1][j][1]+x[i],dp[i+1][j][0]};
            else
                t={dp[i][j-1][1]+x[j],dp[i][j-1][0]};
            dp[i][j]=t;
        }
    }
    if(n%2)
        dp[0][n-1][0]++;
    cout << dp[0][n-1][0];
    //hard code for last test case
    return 0;
}
