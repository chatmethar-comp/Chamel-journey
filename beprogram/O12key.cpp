#include<bits/stdc++.h>
using namespace std;
const int mxN=1e3;
int m, dp[mxN+1][mxN+1];
string a, b, t;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> a >> b >> m;
    while(m--){
        cin >> t;
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=0;i<=a.size();i++){
            for(int j=0;j<=b.size();j++){
                if(!dp[i][j])
                    continue;
                if(a[i]==t[i+j])
                    dp[i+1][j]=1;
                if(b[j]==t[i+j])
                    dp[i][j+1]=1;
            }
        }
        if(dp[a.size()][b.size()])
            cout << "Yes\n";
        else
            cout << "No\n";
//        for(int i=0;i<5;i++){
//            for(int j=0;j<5;j++){
//                cout << dp[i][j];
//            }
//            cout <<endl;
//        }
    }
    return 0;
}
