#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(b==0 && c!=0){
        if(c>0){
            cout << "No Solution";
            return 0;
        }
        int i;
        for(i=1;i*i<=a;i++){}
        i--;
        int j;

        for(j=1;j*j<=abs(c);j++){}
        j--;
//        cout << i << j << endl;
        if(i*i==a && j*j==abs(c)){
            cout << i << " " << j*-1 << " " << i << " " << j;
            return 0;
        } else {
            cout << "No Solution";
            return 0;
        }
        return 0;
    }
    if(c==0 && b!=0){
        for(int i=2;i<=b;i++){
            if(a%i==0 && b%i==0){
                cout << a/i << " " << b/i << " " << i << " " << 0;
                return 0;
            }
        }
        cout << "No Solution";
        return 0;
    }
    if(b==0 && c==0){
        cout << 1 << " " << 0 << " " << a << " " << 0;
        return 0;
    }
    int num=a*100 + abs(b)*10 + abs(c);
    for(int i=1;i<=a;i++){
        for(int k=1;k<=c;k++){
            for(int j=1;j*i<=a;j++){
                for(int l=1;l*k<=c;l++){
//                    cout << i << " " << k << " " << j << " " << l << " " << (i*10+j)*(k*10+l) << endl;

                    if((i*10+k)*(j*10+l)==num){
                        if(b<0 && c>0){
                            k=k*-1;
                            l=l*-1;
                        } else if(b<0 && c<0){
                            l=l*-1;
                        } else if(b>0 && c<0){
                            k=k*-1;
                        }
                        cout << i << " " << k << " " << j << " " << l;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No Solution";
    return 0;
}
