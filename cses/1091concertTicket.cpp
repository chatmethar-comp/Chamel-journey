#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=2e5;
ll n, m, a, t;
int main()
{
    cin >> n >> m;
    set<ar<ll,2>> s;
    for(int i=0;i<n;i++){
        cin >> a;
        s.insert({a,i});
    }
    for(int i=0;i<m;i++){
        cin >> t;
        auto it=s.lower_bound({t+1,0});
        if(it==s.begin())
            cout << "-1\n";
        else{
            it--;
            cout << (*it)[0] << endl;
            s.erase(it);
        }
    }
    return 0;
}
