#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int digit[n];
    for(int i=0;i<n;i++){
        cin >> digit[i];
    }
    sort(digit,digit+n);
    for(int i=0;i<n;i++){
        if(digit[i]!=0){
            cout << digit[i];
            digit[i]=-1;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(digit[i]>=0){
            cout << digit[i];
        }
    }
    return 0;
}
