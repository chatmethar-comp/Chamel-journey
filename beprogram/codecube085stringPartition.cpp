#include<bits/stdc++.h>
using namespace std;
const int mxN=1e5+1;
int n, mn=INT_MAX;
short a[mxN], d[50005][26];
string s;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> s;
    n=s.size();
    for(int i=0;i<n;i++)
        a[i]=s[i]-'a';
    for(int k=1;k<=n/2;k++){
        if(n%k==0){
            int c=0;
            memset(d, 0, sizeof(d));
            for(int i=0;i<n;i++)
                d[i%k][a[i]]++;
            for(int i=0;i<k;i++){
                int mx=0;
                for(int j=0;j<26;j++)
                    mx=max(mx,(int)d[i][j]);
                c+=(n/k-mx);
            }
            mn=min(mn,c);
        }
    }
    cout << mn;
    return 0;
}
