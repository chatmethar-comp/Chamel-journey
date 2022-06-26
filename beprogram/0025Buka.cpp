#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    char opr;
    cin >> a >> opr >> b;
    if(opr=='*'){
        cout << 1;
        int zero=a.length() + b.length()-2;
        for(int i=0;i<zero;i++){
            cout << 0;
        }
    }
    if(opr=='+'){
//        for(int i_a=a.length()-1, i_b=b.length()-1;i_a>=0 || i_b>=0;i_a--,i_b--){
//            cout << a[i]
//        }
        if(a.length()==b.length()){
            cout << 2;
            for(int i=0;i<a.length()-1;i++){
                cout << 0;
            }
        } else {
            int la=a.length();
            int lb=b.length();
            cout << 1;
            for(int i=1;i<max(la,lb);i++){
                if(i==max(la,lb)-min(la,lb)){
                    cout << 1;
                } else {
                    cout << 0;
                }
            }
        }

    }
    return 0;
}
