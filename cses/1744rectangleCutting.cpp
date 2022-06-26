#include<bits/stdc++.h>
using namespace std;
const int mxN=501;
int dp[mxN][mxN];
int a, b, c=0;
int main()
{
    cin >> a >> b;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i==j){
                dp[i][j]=0;
                continue;
            }
            if(i>1||j>1)
                dp[i][j]=1e9;
            for(int k=1;k<i;k++){
//                cout << i << " " << j<< " " << k << " " << dp[k][j]+dp[i-k][j]+1 << endl;
                dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
            }
            for(int k=1;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
            }
        }
    }
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[a][b];
    return 0;
}
