#include<bits/stdc++.h>
using namespace std;
const int mxN=1e6+1;
int n, m, k, lo, cnn[mxN];
int main()
{
    cin >> n >> m >> k >> lo;
    for(int i=0,x;i<n;i++){
        cin >> x;x++;
        cnn[x]++;
    }
    for(int i=1;i<mxN;i++)
        cnn[i]+=cnn[i-1];
    for(int i=0;i<k;i++){
        int l=-1,u=-1,ans=0;
        for(int j=0;j<m;j++){
            int no, lr, ur;
            cin >> no;no++;
            lr=max(1,no-lo);
            ur=min(mxN-1,no+lo);
            if(l==-1){
                l=lr;
                u=ur;
            } else if(u>=lr)
                u=ur;
            else{
                ans+=cnn[u]-cnn[l-1];
                l=lr;
                u=ur;
            }
        }
        ans+=cnn[u]-cnn[l-1];
        cout << ans<< endl;
    }
    return 0;
}
