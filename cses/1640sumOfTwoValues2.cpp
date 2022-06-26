#include<bits/stdc++.h>
using namespace std;
const int mxN=2e5;
int n, x, a;map<int,int> mp;
int main()
{
    cin >> n >> x;
    for(int i=0;i<n;i++){
        cin >> a;
        if(mp.find(x-a)!=mp.end()){
            cout << mp[x-a]+1 << " " << i+1;
            return 0;
        }
        mp[a]=i;
    }
    cout << "IMPOSSIBLE";
    return 0;
}
