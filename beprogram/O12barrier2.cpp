#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=6e6;
int n, w, mx=0, l=INT_MAX, qs[mxN+1];
deque<ar<int,2>> v;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    qs[0]=0;
    cin >> n >> w;
    for(int i=1;i<=n;i++){
        cin >> qs[i];
        qs[i]+=qs[i-1];
    }
    v.push_back({0,0});
    for(int i=1;i<=n;i++){
        while(v.size()&&i-v.front()[1]>w)
            v.pop_front();
        while(v.size()&&v.back()[0]>=qs[i])
            v.pop_back();
        v.push_back({qs[i],i});
        if(mx<qs[i]-v.front()[0]){
            mx=qs[i]-v.front()[0];
            l=i-v.front()[1];
        } else if(mx==qs[i]-v.front()[0]&&l>i-v.front()[1]){
            l=i-v.front()[1];
        }
    }
    cout << mx << endl << l;
    return 0;
}
