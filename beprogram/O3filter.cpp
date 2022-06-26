#include<bits/stdc++.h>
using namespace std;
int l, w, c, x, b, ans1=0, ans2=0;
int a[5000];
int main()
{
    memset(a,0,sizeof(a));
    cin >> l >> w >> c;
    while(c--){
        cin >> x >> b;
        for(int i=x;i<x+b;i++)
            a[i]++;
    }
    for(int i=0;i<l;i++){
        if(a[i]==0)
            ans1+=w;
        if(a[i]==1)
            ans2+=w;
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
