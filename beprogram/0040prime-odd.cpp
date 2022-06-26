#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string a;
    for(int i=0;i<n;i++){
        cin >> a;
        if(a=="2"||a[a.length()-1]&1){
            cout << "T\n";
        } else {
            cout << "F\n";
        }
    }
    return 0;
}
