#include<bits/stdc++.h>
using namespace std;
int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    int a, b, c, d;
    for(a=1;a<=A;a++){
        if(A%a==0){
            c = A/a;
            for(b=-abs(C);b<=abs(C);b++){
                if(b!=0 && C%b==0){
                    d=C/b;
                    if(a*d + b*c==B){
                        cout << a << " " << b << " " << c << " " << d;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No Solution";
    return 0;
}
