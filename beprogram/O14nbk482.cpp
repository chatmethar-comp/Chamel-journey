#include<bits/stdc++.h>
using namespace std;
const int mxN=1e5;
#define ar array
int n, m, a[mxN], s=0;
set<ar<int,2>> q;
int x, ans;
int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        q.insert({s+a[i],i});
        s+=a[i];
    }
    while(m--){
        ans=0;
        cin >> x;
        for(ar<int,2> c : q){
            if(x<c[0]){
                break;
            } else {
                if(c[1]>ans){
                    ans=c[1];
                    if(c[0]<0)
                        ans++;
                }
            }
        }

        cout << ans+1 << endl;
    }
    return 0;
}
