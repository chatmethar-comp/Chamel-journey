#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int count=0;
    while(a>1 || b>1 || c>1){
        if(a>=b && a>=c){
            if(a%2==0){
                a/=2;
            }else{
                a--;
                a=a/2;
            }
        } else if (b>a && b>=c){
            if(b%2==0){
                b/=2;
            } else {
                b--;
                b=b/2;
            }
        } else if (c>a && c>b){
            if(c%2==0){
                c/=2;
            } else {
                c--;
                c=c/2;
            }
        }
        count++;
//        cout << count << " " << a << " " << b << " " << c << endl;
    }
    cout << count;
    return 0;
}
