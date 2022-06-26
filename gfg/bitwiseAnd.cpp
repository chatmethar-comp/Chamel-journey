#include<bits/stdc++.h>
using namespace std;

string bits(int num){
    string a="";
    int quotient;
    while(num>0){
        quotient = num%2;
        num = num/2;
        cout << quotient << endl;
        a= to_string(quotient) + a;
    }
    return a;
}
int main()
{
    cout << bits(13);
}
