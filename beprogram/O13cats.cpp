#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=2e6+5;
int n, c[mxN];
ll l=0, r=1e15;
bool ch;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> c[i];
    }
    while(l<r){
        vector<int> ans;
        ll mid=(l+r)>>1;
        ch=0;
        for(int i=0;i<n;i++){
            if(mid<c[i])
                ans.push_back(c[i]);
        }
        for(int i=0;i<ans.size();i+=2){
            if(ans[i]!=ans[i+1]){
                ch=1;
                break;
            }
        }
        if(ch)
            l=mid+1;
        else
            r=mid;
    }
    return 0;
}
