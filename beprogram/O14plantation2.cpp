#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=1e5;
ll t, n, r, d;
ar<ll,2> p[mxN];
int main()
{
    cin >> t;
    while(t--){
        cin >> n >> r >> d;
        for(ll i=0;i<n;i++){
            cin >> p[i][0] >> p[i][1];
        }
        bool ch=0;
        sort(p,p+n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ll dx=p[j][0]-p[i][0], dy=p[j][1]-p[i][1];
                if(dx>d+2*r||dy>d+2*r)
                    break;
                if(dx*dx + dy*dy < (d+2*r)*(d+2*r)){
                    ch=1;
                    cout << "N\n";
                    break;
                }
            }
            if(ch)break;
        }
        if(!ch)cout<<"Y\n";
    }
    return 0;
}
