#include<bits/stdc++.h>
using namespace std;
int main()
{
    int d;
    int I=0, V=0, X=0, L=0, C=0;
    cin >> d;
    for(int i=1;i<=d;i++){
        int num=i;
        while(num>=100){
            C++;
            num-=100;
        }
        if(num>=90){
            X++;
            C++;
            num-=90;
        }
        if(num>=50){
            L++;
            num-=50;
        }
        if(num>=40){
            X++;
            L++;
            num-=40;
        }
        while(num>=10){
            X++;
            num-=10;
        }
        if(num==9){
            I++;
            X++;
            num-=9;
        }
        if(num>=5){
            V++;
            num-=5;
        }
        if(num==4){
            I++;
            V++;
            num-=4;
        }
        I+=num;
    }
    cout << I << " " << V << " " << X << " " << L << " " << C << endl;
    return 0;
}
// I  V  X   L   C
// 1  5  10  50  100
