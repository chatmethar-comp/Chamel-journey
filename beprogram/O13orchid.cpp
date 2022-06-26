#include<bits/stdc++.h>
using namespace std;
const int mxN=1e6;
int dp[mxN];
int main()
{
    int n, num, lis=0, idx, ans=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> num;
        idx=upper_bound(dp,dp+lis,num)-dp;
        dp[idx]=num;
        if(lis==idx)
            lis++;
    }
    cout << n-lis << endl;
    return 0;
}
