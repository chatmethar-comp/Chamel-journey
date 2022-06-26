#include<bits/stdc++.h>
using namespace std;
char a[200][200];
int r, c, i1, i2;
int jl, j2, s1=0, s2=0;
int main()
{
    cin >> r >> c;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            cin >> a[i][j];
    int f=0;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(a[i][j]=='x'){
                i1=i;j1=j;
                while(a[i1][j1+s1+1]=='x'&&a[i1+s1+1][j1]=='x'){
                    s1++;
                }
                f=1;
                break;
            }
        }
        if(f)break;
    }
    for(int i=i1;i<i1+s1;i++){
        for(int j=j1;j<j1+s1;j++)
            a[i][j]='.'
    }
    for(int i=r;i>=1;i--){
        for(int j=c;j>=1;j--){
            if(g[i][j]=='x'){
                i2=i;j2=j;
                while(a[i2][j2-s2-1]=='x'||a[i2-s2-1][j2]=='x'){
                    s2++;
                }
                f=1;
                break;
            }
        }
        if(f)break;
    }
    cout << i1 << " " << j2 << " " << s1 << endl;
    cout << i2-s2 << " " << j2-s2 << " " << s2  << endl;
    return 0;
}
