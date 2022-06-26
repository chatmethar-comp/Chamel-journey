#include<bits/stdc++.h>
using namespace std;
int t, n, k;
int main()
{
    cin >> t;
    while(t--){
        cin >> n >> k;
        int l=0;
        while(k+l<n){
            l=l*2+1;
        }
        if(k+l==n||k+1>n)
            cout << "B\n";
        else
            cout << "A\n";
    }
    return 0;
}
