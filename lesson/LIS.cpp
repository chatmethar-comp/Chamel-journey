#include<bits/stdc++.h>
using namespace std;
int dp[100];
int main()
{
    int n, num, lis=0, idx;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> num;
        idx=upper_bound(dp,dp+lis,num)-dp;
        dp[idx]=num;
        if(lis==idx)
            lis++;
    }
    cout << lis;
    return 0;
}
