#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=1e4, mxM=1e5;
vector<int> adj[mxN];
int k, n, m, dp[mxN+1];
int main()
{
    memset(dp,0x3f,sizeof(dp));
    cin >> k >> n >> m;
    for(int i=0,a,b;i<m;i++){
        cin >> a >> b;
        adj[a].push_back(b);
    }
    dp[1]=0;
    for(int i=1;i<=n;i++){
        for(int j : adj[i]){
            dp[j]=min(dp[j],dp[i]+1);
        }
    }
    for(int i=n;i>=1;i--){
        if(dp[i]<=k){
            cout << i;
            return 0;
        }
    }
    return 0;
}
