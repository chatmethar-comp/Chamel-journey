#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=5e6;
int n, k, h[mxN];
vector<ll> p;
int main()
{
    cin >> n >> k;
    for(int i=0;i<n;++i){
        cin >> h[i];
    }
    for(int i=0;i<n;i++){
        if((i+1>=n||h[i]>h[i+1])&&(i-1<0||h[i]>h[i-1]))
            p.push_back(h[i]);
    }
    if(p.size()==0){
        cout << "-1";
        return 0;
    }
    sort(p.begin(),p.end());
    p.resize(unique(p.begin(),p.end())-p.begin());
    if((int)p.size()<k){

        for(ll i : p)
            cout << i << endl;
        return 0;
    }
    reverse(p.begin(),p.end());
    for(int i=0;i<k;i++)
        cout << p[i] << endl;


    return 0;
}
