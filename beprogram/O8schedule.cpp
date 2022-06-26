#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=1e3+1;
int m, n, x[mxN], y[mxN];
ar<ll,2> dp[mxN][mxN];
int main()
{
    cin >> m >> n;
    for(int i=1;i<=n;i++)
        cin >> x[i];
    for(int i=1;i<=n;i++)
        cin >> y[i];
    dp[0][0]={0,1};
    for(int i=1;i<=n;i++){
        if(dp[0][i-1][0]+y[i]<=m)
            dp[0][i]={dp[0][i-1][0]+y[i],dp[0][i-1][1]};
        else
            dp[0][i]={y[i],dp[0][i-1][1]+1};
    }
    for(int i=1;i<=n;i++){
        if(dp[i-1][0][0]+x[i]<=m)
            dp[i][0]={dp[i-1][0][0]+x[i],dp[i-1][0][1]};
        else
            dp[i][0]={x[i],dp[i-1][0][1]+1};
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ar<ll,2> t1, t2;
            //t1
            if(dp[i-1][j][0]+x[i]<=m)
                t1={dp[i-1][j][0]+x[i],dp[i-1][j][1]};
            else
                t1={x[i],dp[i-1][j][1]+1};
            //t2
            if(dp[i][j-1][0]+y[i]<=m)
                t2={dp[i][j-1][0]+y[i],dp[i][j-1][1]};
            else
                t2={y[i],dp[i][j-1][1]+1};

            if(t1[1]<t2[1])
                dp[i][j]=t1;
            else if(t1[1]==t2[1]&&t1[0]<t2[0])
                dp[i][j]=t1;
            else
                dp[i][j]=t2;
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout << dp[i][j][1] << " " << dp[i][j][0] << "\t";
        }
        cout << endl << endl;
    }
    cout << dp[n][n][1] << endl << dp[n][n][0];
    return 0;
}
