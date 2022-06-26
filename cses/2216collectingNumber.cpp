#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=2e5;
int n, a, pos[mxN+5], c=1;
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a;
        pos[a]=i;
    }
    for(int i=2;i<=n;i++){
        if(pos[i-1]>pos[i]){
            c++;
        }
    }
    cout << c;
    return 0;
}
