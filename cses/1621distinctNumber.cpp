#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, c=0;
ll x;
set<ll> s;
int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        if(s.find(x)==s.end()){
            s.insert(x);
            c++;
        }
    }
    cout << c;
    return 0;
}
