#include<bits/stdc++.h>
using namespace std;
#define sqrt2 sqrt(2)
int main()
{
    double x=0, y=0;
    string str;
    do{
//        cout << x << " " << y << endl;
        cin >> str;
        if(str.length()==2){
            if(str[1]=='N'){
                y+=str[0]-'0';
            } else if(str[1]=='S'){
                y-=str[0]-'0';
            } else if(str[1]=='E'){
                x+=str[0]-'0';
            } else if(str[1]=='W'){
                x-=str[0]-'0';
            }
        } else {
            if(str[1]=='N' && str[2]=='E'){
                x+=(str[0]-'0')/sqrt2;
                y+=(str[0]-'0')/sqrt2;
            } else if(str[1]=='N' && str[2]=='W'){
                x-=(str[0]-'0')/sqrt2;
                y+=(str[0]-'0')/sqrt2;
            } else if(str[1]=='S' && str[2]=='E'){
                x+=(str[0]-'0')/sqrt2;
                y-=(str[0]-'0')/sqrt2;
            } else if(str[1]=='S' && str[2]=='W'){
                x-=(str[0]-'0')/sqrt2;
                y-=(str[0]-'0')/sqrt2;
            }
        }
    }while(str[0]!='*');
    printf("%.3f %.3f\n%.3f", x, y, sqrt(x*x + y*y));

    return 0;
}
