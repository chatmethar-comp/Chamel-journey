#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=6e6;
ll n, w, qs[mxN+1], mx=0, l=0;
deque<ar<ll,2>> s;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> w;
    for(int i=1;i<=n;i++){
        cin >> qs[i];
        qs[i]+=qs[i-1];
    }
    s.push_back({0,0});
    for(int i=1;i<=n;i++){
        while(s.size()&&i-s.front()[1]>w)
            s.pop_front();
        while(s.size()&&qs[i]<=s.back()[0])
            s.pop_back();
        s.push_back({qs[i],i});
        if(mx<qs[i]-s.front()[0]){
            mx=qs[i]-s.front()[0];
            l=i-s.front()[1];
        }
        if(mx==qs[i]-s.front()[0]&&l>i-s.front()[1])
            l=i-s.front()[1];
    }
    cout << mx << endl << l;
}
