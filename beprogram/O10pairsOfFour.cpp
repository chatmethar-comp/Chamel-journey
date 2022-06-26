#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=1e3;
ll n, dp[mxN+5][mxN+5];
char ch[mxN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> ch[i];
    }
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if(ch[i]==ch[j]){
                dp[i][j]=dp[i+1][j-1]+1;
            }
            for(int k=i;k<=j;k++){
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
        }
    }
    cout << dp[0][n-1];
    return 0;
}
