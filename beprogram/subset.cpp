#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int Set[n+1];
    for(int i=1;i<=n;i++){
        cin >> Set[i];
    }
    int poss = (1<<n)-1;
    for(int i=1;i<poss;i++){
        cout << "{";
        for(int j=1,bit=i;j<=i;j++,bit=bit>>1){
            if(bit%2){
                if(j!=i && j!=1){
                    cout << " ";
                }
                cout << Set[j];
            }
            if(j==i){
                cout << "}, ";
            }
        }
    }
}
