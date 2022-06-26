#include<bits/stdc++.h>
using namespace std;
int n, c, r[10], a[10], p;
int main()
{
    cin >> n >> c;
    for(int i=0,a;i<c;i++){
        cin >> a;
        r[i]=a;
    }
    for(int i=0;i<n;i++){
        a[i]=i+1;
    }
    do{
        p=0;
        for(int i=0;i<c;i++)
            if(a[0]==r[i]){
                p=1;
                break;
            }
        if(p) continue;
        for(int i=0;i<n;i++)
            cout << a[i] << " ";
        cout << endl;
    }while(next_permutation(a,a+n));
}
