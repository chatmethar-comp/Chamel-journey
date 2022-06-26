#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s[n];
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    int index;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            index=0;
            if(s[i]==s[j]){
                s[j]="-1";
                continue;
            }
            while(s[i][index]==s[j][index]){
                index++;
            }
            if(s[i][index] > s[j][index]){
                string temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]!="-1"){
            cout << s[i] << endl;
        }
    }
    return 0;
}
