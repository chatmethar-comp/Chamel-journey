#include<bits/stdc++.h>
using namespace std;
#define ll long long
int r, c, o, a, b;
ll dp[55][55];
int main()
{
    memset(dp,0,sizeof(dp));
    cin >> c >> r >> o;
    for(int i=0;i<o;i++){
        cin >> a >> b; // 2 3 // 2 2
        dp[r-b+1][a]=-1;
    }

    for(int i=r;i>=0;i--){
        for(int j=1;j<=c;j++){
            if(dp[i][j]==-1){
                dp[i][j]=0;
                continue;
            }
            if(i==r&&j==1){
                dp[i][j]=1;
                continue;
            }
            if(i!=r){
                dp[i][j]+=dp[i+1][j];
            }
            if(j!=1){
                dp[i][j]+=dp[i][j-1];
            }
        }
    }
//    for(int i=1;i<=r;i++){
//        for(int j=1;j<=c;j++){
//            cout << dp[i][j] << " ";
//        }
//        cout <<endl;
//    }
    cout << dp[1][c];
    return 0;
}
