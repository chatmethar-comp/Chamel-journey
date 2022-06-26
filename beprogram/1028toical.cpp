#include<bits/stdc++.h>
using namespace std;
int main()
{
    string equ;
    cin >> equ;
    int ch[26];
    for(int i=0;i<26;i++){
        ch[i]=0;
    }
    while(equ[0]!='!'){
        cout << equ;
        if(equ[0]=='='){
            cout << equ[2] << " " << equ[4] << endl;
            ch[equ[2]] = equ[4];
        } else if(equ[0]=='+'){
            cout << "+con" << endl;
            ch[equ[2]-'A'] += ch[equ[4]-'A'];
        } else if(equ[0]=='-'){
            ch[equ[2]-'A'] -= ch[equ[4]-'A'];
        } else if(equ[0]=='#'){
            cout << ch[equ[2]-'A'];
        }
        cin >> equ;
    }
    return 0;
}
