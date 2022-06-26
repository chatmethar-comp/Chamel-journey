#include<bits/stdc++.h>
using namespace std;
const int mxN=100, mxM=1e5+1;
int n, x[mxN], dp[mxM];
vector<int> ans;
int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> x[i];
    dp[0]=1;
    for(int j=0;j<n;j++)
        for(int i=1e5;i;i--)
            if(i>=x[j])
                dp[i]|=dp[i-x[j]];
    for(int i=1;i<=1e5;i++)
        if(dp[i])
            ans.push_back(i);
    cout << ans.size() << endl;
    for(int a : ans)
        cout << a << " ";
    return 0;
}
