#include<bits/stdc++.h>
using namespace std;
const int mxN=105;
int n;
bool isNugget[mxN];
int main()
{
    // Pre-computation
    isNugget[0]=1;
    for(int i=6;i<=100;i++){
        if(i>=6 && isNugget[i-6])
            isNugget[i]=1;
        if(i>=9 && isNugget[i-9])
            isNugget[i]=1;
        if(i>=20 && isNugget[i-20])
            isNugget[i]=1;
    }
    cin >> n;
    if(n<6)
        cout << "no";
    else{
        for(int i=6;i<=n;i++){
            if(isNugget[i]){
                cout << i << endl;
            }
        }
    }
    return 0;
}
