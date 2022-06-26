#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    string s[n];
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    int t;
    cin >> t;
    int len;
    string check;
    int ok[n];
    for(int i=0;i<n;i++){
        ok[i]=0;
    }
    while(t--){
        for(int i=0;i<n;i++){
            ok[i]=0;
        }
        cin >> len;
        cin >> check;
        for(int i=0;i<len;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<m;k++){
                    if(check[i]!=s[j][k]){
                        continue;
                    }
                    int checked=0;
                    while(check[i+checked]==s[j][k+checked]){
                        checked++;
                    }
                    if(checked==m){
                        ok[j]=1;
                    }
                }
            }
        }
        bool count=false;
        for(int i=0;i<n;i++){
            if(ok[i]){
                cout << i+1 << " ";
                count=true;
            }
        }
        if(!count){
            cout << "OK";
        }
        cout << endl;
    }
    return 0;
}
