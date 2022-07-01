#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=2e8, mxM=2e5;
vector<ar<int,2>> v;
int m, n;
ll pc[4]; // prime 2, 3, 5, 7
int main()
{
    cin >> m >> n;
    for(int i=0,x,s,t;i<m;i++){
        cin >> x >> s >> t;
        v.push_back({s,x});
        v.push_back({t+1,-x});
    }
    sort(v.begin(),v.end());
    ll maxn=1, ans1=0, ans2=0;
    for(int i=0;i<v.size();i++){
        if(v[i][1]>0){
            switch(v[i][1]){
                case 2: pc[0]++; break;
                case 3: pc[1]++; break;
                case 4: pc[0]+=2; break;
                case 5: pc[2]++; break;
                case 6: pc[0]++; pc[1]++; break;
                case 7: pc[3]++; break;
                case 8: pc[0]+=3; break;
                case 9: pc[1]+=2; break;
                case 10: pc[0]++; pc[2]++; break;
            }
            maxn=1;
            for(int j=0;j<4;j++)
                maxn*=(1+pc[j]);
            if(maxn > ans1){
                ans1=maxn;
                ans2=v[i+1][0]-v[i][0];
            } else if (maxn==ans1){
                ans2+=v[i+1][0]-v[i][0];
            }
        }
        else{
            maxn/=(-v[i][1]);
            switch(-v[i][1]){
                case 2: pc[0]--; break;
                case 3: pc[1]--; break;
                case 4: pc[0]-=2; break;
                case 5: pc[2]--; break;
                case 6: pc[0]--; pc[1]--; break;
                case 7: pc[3]--; break;
                case 8: pc[0]-=3; break;
                case 9: pc[1]-=2; break;
                case 10: pc[0]--; pc[2]--; break;
            }
        }
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
