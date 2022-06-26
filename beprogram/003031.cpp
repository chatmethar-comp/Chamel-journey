#include<bits/stdc++.h>
using namespace std;
int main()
{
    string num;
    cin >> num;
    int sum3=0, sum11=0;
    for(int i=0;i<num.length();i++){
        sum3=(sum3*10 + num[i]-'0')%3;
        sum11=(sum11*10 + num[i]-'0')%11;
    }
    cout << sum3 << " " << sum11;
    cout << endl;
}
