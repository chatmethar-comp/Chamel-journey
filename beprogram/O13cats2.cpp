#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=2e6+5;
ll n, c[mxN];
bool ch;
int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> c[i];
    }
    ll l=0, r=1e15;
    while(l<r){
        vector<int> big;
        ch=0;
        ll mid=(l+r)>>1;
        for(int i=0;i<n;i++){
            if(c[i]>mid){
                big.push_back(c[i]);
            }
        }
        for(int i=0;i<big.size();i+=2){
            if(big[i]!=big[i+1]){
                ch=1;
                break;
            }
        }
        if(ch)
            l=mid+1;
        else
            r=mid;
//        cout << l << " " << mid << " " << r << endl;
    }
    cout << l;
    return 0;
}
