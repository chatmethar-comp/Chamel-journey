#include<bits/stdc++.h>
using namespace std;
const int mxN=5e3+1;
int dp[mxN][mxN];
string s, t;
int main()
{
    cin >> s >> t;
    for(int i=1;i<=t.size();i++)
        dp[0][i]=i;
    for(int i=1;i<=s.size();i++)
        dp[i][0]=i;
    for(int i=1;i<=s.size();i++){
        for(int j=1;j<=t.size();j++){
            dp[i][j]=1e9;
            if(s[i-1]==t[j-1])
                dp[i][j]=dp[i-1][j-1];
            dp[i][j]=min({dp[i][j]-1,dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
        }
    }
    cout << dp[s.size()][t.size()];
    return 0;
}
