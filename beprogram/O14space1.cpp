#include<bits/stdc++.h>
using namespace std;
const int mxN=1e4, mxM=2e3;
int r, c, di[]={0,1,0}, dj[]={-1,0,1}, p=0, s=0, t=0, i1, i2, j3, j4;

string ss;
bitset<2000> b[mxN];
bool e(int i, int j)
{
    return i<0||i>=r||j<0||j>=c;
}

void Clear(int i,int j)
{
    if(e(i,j)||b[i][j]==0)
        return;
    b[i][j]=0;
    i1=min(i1,i);
    i2=max(i2,i);
    j3=min(j3,j);
    j4=max(j4,j);
    for(int k=0;k<3;k++){
        Clear(i+di[k],j+dj[k]);
    }
}

int main()
{

    cin >> c >> r;
    for(int i=0;i<r;i++){
        cin >> ss;
        for(int j=0;j<c;j++){
            b[i][j]=ss[j]-'0';
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(b[i][j]){
                if(b[i+1][j]&&b[i][j+1]){
                    p++;
                    Clear(i,j);
                    continue;
                }
                i1=INT_MAX, i2=0, j3=INT_MAX, j4=0;
                Clear(i,j);
                if(i2-i1==j4-j3)
                    s++;
                else
                    t++;

            }
        }
    }
    cout << p << " " << s << " " << t;
    return 0;
}
