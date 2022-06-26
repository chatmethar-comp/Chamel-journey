#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=5e5;
ll n, h[mxN], p[mxN], s=0, t, idx, lw=1e9, ans1=0, ans2=0;
int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> h[i];
    }
    for(int i=0;i<n;i++){
        cin >> p[i];
        if(lw>p[i])
            lw=p[i];
        s+=p[i];
    }
    s=s/n;
    for(int i=0;i<n;i++){
        ans1+=p[i]-lw;
    }
    for(int i=0;i<n;i++){
        if(s>p[i]){
            p[i]=h[i];
            ans2++;
        }
        ans2+=p[i]-s;
    }
    if(ans1<ans2)
        cout << lw << " "<< ans1;
    else
        cout << s << " " << ans2;
    return 0;
}
