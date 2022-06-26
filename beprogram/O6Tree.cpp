#include<bits/stdc++.h>
using namespace std;
#define ar array
#define all(x) x.begin(),x.end()

vector<pair<int,int>> t1,t2;
int n, u, v;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int t=5;
    while(t--){
        cin >> n;
        for(int i=0;i<n-1;i++){
            cin >> u >> v;
            if(u>v)
                swap(u,v);
            t1.push_back({u,v});
        }
        for(int i=0;i<n-1;i++){
            cin >> u >> v;
            if(u>v)
                swap(u,v);
            t2.push_back({u,v});
        }
        sort(all(t1));
        sort(all(t2));
        if(t1==t2)
            cout << "Y";
        else
            cout << "N";
        t1.clear();
        t2.clear();
    }
    return 0;
}
