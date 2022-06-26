#include<bits/stdc++.h>
using namespace std;
const int mxN=1e5+5;
int n, m, p[mxN], a[mxN];
int Find(int i)
{
    if(p[i]==i)
        return i;
    return p[i]=Find(p[i]);
}
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        p[i]=i;
        cin >> a[i];
    }
    int i, j, pi, pj;
    while(m--){
        cin >> i >> j;
        pi=Find(i);pj=Find(j);
        if(pi==pj)
            cout << "-1\n";
        else if(a[pi]>a[pj]){
            cout << pi << endl;
            a[pi]+=a[pj]/2;
            p[pj]=pi;
        }
        else if(a[pj]>a[pi]){
            cout << pj << endl;
            a[pj]+=a[pi]/2;
            p[pi]=pj;
        } else if(pi<pj){
            cout << pi << endl;
            a[pi]+=a[pj]/2;
            p[pj]=pi;
        } else {
            cout << pj << endl;
            a[pj]+=a[pi]/2;
            p[pi]=pj;
        }
    }
    return 0;
}
