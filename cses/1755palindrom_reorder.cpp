#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int c[26]={}, c1=0;
    for(char d : s){
        c[d-'A']++;
    }
//    for(int i : c){
//        cout << i << " ";
//    }
//    cout << endl;
    for(int i=0;i<26;i++){
        c1 += c[i]%2;
    }
    if(c1>1){
        cout << "NO SOLUTION";
        return 0;
    }
    string t;
    for(int i=0;i<26;i++){
        if((c[i]%2)^1){
            for(int j=0;j<c[i]/2;j++){
                t+=(char)('A'+i);
            }
        }
    }
    cout << t;
    for(int i=0;i<26;i++){
        if(c[i]%2){
            for(int j=0;j<c[i];j++){
                cout << (char)('A'+i);
            }
            break;
        }
    }
    reverse(t.begin(), t.end());
    cout << t;
    return 0;
}
