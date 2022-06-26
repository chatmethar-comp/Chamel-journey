#include<bits/stdc++.h>
using namespace std;
const int mxN=1e6, MOD=1e9+7;
int n, x, c[100], dp[mxN+1];
int main()
{
    cin >> n >> x;
    for(int i=0;i<n;i++){
        cin >> c[i];
    }
    dp[0]=1;
    for(int j=0;j<n;j++){
        for(int i=1;i<=x;i++)
            if(i>=c[j])
                dp[i]=(dp[i]+dp[i-c[j]])%MOD;
//        for(int i=1;i<=x;i++)
//            cout << dp[i] << " ";
//        cout << endl;
    }
    cout << dp[x];
    return 0;
}
