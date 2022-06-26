// 70/100
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r, c, i1, j1, i2, j2, s1, s2, f=0;
    char b[200][200];
    cin >> r >> c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> b[i][j];

        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(b[i][j]=='x'){
//                cout << i << " " << j << endl;
                i1=i;j1=j;
                int k=1;
                while(i+k<r&&j+k<c&&b[i][j+k]=='x'&&b[i+k][j]=='x'){
                    k++;
                }
                s1=k;
                f=1;
                break;
            }
        }
        if(f)break;
    }
    for(int i=i1;i<i1+s1;i++)
        for(int j=j1;j<j1+s1;j++)
            b[i][j]='.';
    f=0;
    for(int i=r-1;i>=0;i--){
        for(int j=c-1;j>=0;j--){
            if(b[i][j]=='x'){
                i2=i;j2=j;
                int k=1;
                while(b[i][j-k]=='x'||b[i-k][j]=='x'){

                    k++;
                }
                s2=k;
                i2+=-k+1;j2+=-k+1;
                f=1;
                break;
            }
        }
        if(f)break;
    }
    cout << i1+1 << " " << j1+1 << " " << s1 << endl;
    cout << i2+1 << " " << j2+1 << " " << s2 << endl;
}
