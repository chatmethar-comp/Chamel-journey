#include<bits/stdc++.h>
using namespace std;

int solve(int i,int S[], int B[], int s, int b, int ans, int n){
    if(abs(s-b)<ans){
        ans = abs(s-b);
    }
    for(int i=s+1;i<n;i++){
        solve(i,S,B,s*S[i],b+B[i],ans,n);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int S[n], B[n];
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        cin >> S[i] >> B[i];
    }
    for(int i=0;i<n;i++){
        ans = solve(i, S, B, S[i], B[i], ans, n);
    }
    cout << ans;
}
