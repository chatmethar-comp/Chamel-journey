#include<bits/stdc++.h>
using namespace std;
#define ar array
const int mxN=6e6+1;
int n, m, qs[mxN];
deque<ar<int,2>> dq;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    qs[0]=0;
    for(int i=1;i<=n;i++){
        cin >> qs[i];
        qs[i]+=qs[i-1];
    }
    int mx=0, len=INT_MAX;
    dq.push_back({0,0});
    for(int i=1;i<=n;i++){
        while(dq.size()&&i-dq.front()[1]>m)
            dq.pop_front();
        while(dq.size()&&qs[i]<=dq.back()[0])
            dq.pop_back();
        dq.push_back({qs[i],i});
        if(mx<qs[i]-dq.front()[0]){
            mx=qs[i]-dq.front()[0];
            len=i-dq.front()[1];
        } else if(mx==qs[i]-dq.front()[0]){
            len=min(len,i-dq.front()[1]);
        }
    }
    if(mx==-1)
        cout << "0\n0";
    else
        cout << mx << endl << len;
    return 0;
}
