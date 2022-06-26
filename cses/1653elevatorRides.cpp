#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=20, mxX=1e9;
int n;
ll a[mxN], x, dp[mxN+1][mxN+1];

ll solve(int n, ll w)
{
//    cout << n << endl;
    if(n==0)
        return 0;
    if(w+a[n-1]>x)
        return 1+solve(n-1,a[n-1]);
    return min(solve(n-1,w+a[n-1]),1+solve(n-1,a[n-1]));
}

int main()
{
    cin >> n >> x;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cout << solve(n,0);
    return 0;
}
