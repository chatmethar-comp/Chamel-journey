#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=1e3;
int n, q;
map<vector<ar<int,2>>,int> mv;
int main()
{
    cin >> n >> q;
    for(int i=0,a;i<n;i++){
        cin >> a;
        vector<ar<int,2>> ve;
        for(int j=1,u,v;j<a;j++){

            cin >> u >> v;
            if(u>v)
                swap(u,v);
            ve.push_back({u,v});
        }
        sort(ve.begin(),ve.end());
        mv[ve]++;
    }
    for(int i=0,a;i<q;i++){
        cin >> a;
        vector<ar<int,2>> ve;
        for(int j=1,u,v;j<a;j++){
            cin >> u >> v;
            if(u>v)
                swap(u,v);
            ve.push_back({u,v});
        }
        sort(ve.begin(),ve.end());
        if(mv.find(ve)!=mv.end())
            cout << mv[ve] << endl;
        else
            cout << "0\n";
    }
    return 0;
}
