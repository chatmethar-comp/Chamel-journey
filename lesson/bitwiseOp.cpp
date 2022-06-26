#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a = 10, b = 7;
    // 10 = 00001010,  7 = 00000111;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "a & b = " << (a&b) << endl;
    // a and b = a&b = 00000010 = 2
    cout << "a | b = " << (a|b) << endl;
    // a or b = a|b = 00001111 = 15
    cout << "a ^ b = " << (a^b) << endl;
    // a xor b = a^b = 00001101 = 13
    cout << "~(" << a << ") = " << (~a) << endl;
    // not a = (~a) = 11110101
    cout << "b << 1 = " << (b<<1) << endl;
    // b left shift 1 = 00001110
    cout << "b >> 1 = " << (b>>1) <<endl;
    // b right shift 1 = 00000011
    cout << "1 << 2" << (1<<2) << endl;
    cout << "i%2 i&1" << endl;
    for(int i=0;i<=10;i++){
        cout << (i%2) << " " << (i&1) << endl;
    }
    int j=10;
    j>>=1;
    cout << j;
    return 0;
}
