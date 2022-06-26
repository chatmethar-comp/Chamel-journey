/*
  [credit]
user: krit3379
submitted at: 13/08/2564 21:45:56
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=1e6;
int n, k, ans=0, temp=0, l=0, f[mxN+5];
vector<ar<int,3>> v;

int val(int x)
{
    int res=0;
    while(x>0){
        res+=f[x];
        x-=(x&-x);
    }
    return res;
}

int low(int k)
{
    int l=1, r=mxN, m, v;
    while(l<r){
        m=(l+r)>>1;
        if(val(m)>k)
            l=m+1;
        else
            r=m;
    }
    return r;
}

int main()
{
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int s,h,o,w;
        cin >> s >> h >> w >> o;
        v.push_back({s,h,o});
        v.push_back({s+w,h,-o});
    }
    sort(v.begin(),v.end());
    for(auto [s,h,o] : v){
        ans+=temp*(s-l);
        for(int i=1;i<=mxN;i+=(i&-i))
            f[i]+=o;
        for(int i=h+1;i<=mxN;i+=(i&-i))
            f[i]+=-o;
        temp=low(k-1)-low(k);
        l=s;
    }
    cout << ans;
}
