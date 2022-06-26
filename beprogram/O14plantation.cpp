#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=1e5;
long long n, t, r, d, dist;
bool ch;
ar<ll,2> p[mxN];
int main()
{
    cin >> t;
    while(t--){
        cin >> n >> r >> d;
        r=2*r+d;
        d=r*r;
        for(int i=0;i<n;i++){
            cin >> p[i][0] >> p[i][1];
        }
        sort(p,p+n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ll dx=p[i][0]-p[j][0], dy=p[i][1]-p[j][1];
                if(abs(dx)>r||abs(dy)>r)
                    break;
                if(dx*dx+dy*dy<d){
                    ch=0;
                    break;
                }
            }
            if(!ch)break;
        }
        cout << (ch?"Y\n":"N\n");
    }
    return 0;
}
