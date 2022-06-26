#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=505;
int r, c, t, i, j, k;
int s[mxN][mxN], in, out;
void play()
{
    memset(s,0,sizeof(s));
    cin >> r >> c >> t;
    while(t--){
        cin >> i >> j;
        s[i+1][j+1]=1;
    }
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    }
    for(i=min(r,c);i>=0;i--){
        for(j=i;j<=r;j++){
            for(k=i;k<=c;k++){
                out=s[j][k]-s[j-i][k]-s[j][k-i]+s[j-i][k-i];
                in=s[j-1][k-1]-s[j-i+1][k-1]-s[j-1][k-i+1]+s[j-i+1][k-i+1];
                if(in==out){
                    cout << i << endl;
                    return;
                }
            }
        }
    }
}
int main()
{
    play();
    play();
    return 0;
}
