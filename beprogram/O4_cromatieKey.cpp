#include<bits/stdc++.h>
using namespace std;
int m, n;
string a, b, c;
char ch[3];
int main()
{
    cin >> m >> n;
    cin >> a >> b >> c;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ch[0]=a[j];
            ch[1]=b[j];
            ch[2]=c[i];
            sort(ch,ch+3);
            c[i]=ch[1];
        }
    }
    cout << c;
    return 0;
}
