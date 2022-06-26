#include<bits/stdc++.h>
using namespace std;
#define ar array
const int mxN=2e3+1;
int m, n, a[mxN], b[mxN];
ar<int,2> dp[mxN][mxN];
int main()
{
    cin >> m >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++)
        cin >> b[i];
    dp[0][0]={1,0};
    for(int i=1;i<=n;i++)
    {
        if(a[i]+dp[0][i-1][1]<=m)
            dp[0][i]={dp[0][i-1][0],a[i]+dp[0][i-1][1]};
        else
            dp[0][i]={dp[0][i-1][0]+1,a[i]};
        if(b[i]+dp[i-1][0][1]<=m)
            dp[i][0]={dp[i-1][0][0],b[i]+dp[i-1][0][1]};
        else
            dp[i][0]={dp[i-1][0][0]+1,b[i]};
    }

//    for(int i=1;i<=n;i++)


    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ar<int,2> t1, t2;
            if(b[i]+dp[i-1][j][1]<=m)
                t1={dp[i-1][j][0],b[i]+dp[i-1][j][1]};
            else
                t1={dp[i-1][j][0]+1,b[i]};
            if(a[j]+dp[i][j-1][1]<=m)
                t2={dp[i][j-1][0],a[j]+dp[i][j-1][1]};
            else
                t2={dp[i][j-1][0]+1,a[j]};
            if(t1[0]<t2[0]||(t1[0]==t2[0]&&t1[1]<=t2[1]))
                dp[i][j]=t1;
            else
                dp[i][j]=t2;
        }
    }
//    for(int i=0;i<=n;i++){
//        for(int j=0;j<=n;j++){
//            cout << dp[i][j][0] << " " << dp[i][j][1] << "\t";
//        }
//        cout << endl << endl;
//    }
    cout << dp[n][n][0] << "\n" << dp[n][n][1];
    return 0;
}
