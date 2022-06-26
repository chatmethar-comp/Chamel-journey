#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=20;
int n;
ll x, a[mxN];
ar<ll,2> dp[1<<mxN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> x;
    for(int i=0;i<n;i++)
        cin >> a[i];
    dp[0]={1,0};
    for(int k=1;k<(1<<n);k++){
        dp[k]={21,0};
        for(int i=0;i<n;i++){
            if(k&(1<<i)){
                cout << i << " " << k << " " << (k^(1<<i)) << endl;
                ar<ll,2> lift=dp[k^(1<<i)];
                if(lift[1]+a[i]<=x)
                    lift[1]+=a[i];
                else{
                    lift[1]=a[i];
                    lift[0]++;
                }
                dp[k]=min(dp[k],lift);
            }
        }
    }
    for(int i=0;i<(1<<n);i++){
        cout << i << " :  " << dp[i][0] <<  " " << dp[i][1] << endl;
    }
    cout << dp[(1<<n)-1][0];
    return 0;
}
