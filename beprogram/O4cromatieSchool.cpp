#include<bits/stdc++.h>
using namespace std;
const int mxN=70;
int n, m, s, ans, f=0, c, mc=INT_MAX;
int di[]={-1,0,1,0}, dj[]={0,-1,0,1};
char a[mxN][mxN], temp[mxN][mxN];
int t[mxN][mxN];

void Clear(int i, int j)
{
    temp[i][j]='S';
    for(int k=0;k<4;k++){
        int ni=i+di[k], nj=j+dj[k];
        if(ni<0||ni>=m||nj<0||nj>=n||temp[ni][nj]!='P')
            continue;
        Clear(ni,nj);
    }
}

int main()
{
    cin >> n >> m;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
            if(a[i][j]=='T'){
                t[i][j]++;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0&&j==0)
                continue;
            if(i==0)
                t[i][j]+=t[i][j-1];
            else if(j==0)
                t[i][j]+=t[i-1][j];
            else
                t[i][j]+=t[i-1][j]+t[i][j-1]-t[i-1][j-1];
        }
    }
    for(int s=min(n,m);s>=1;s--){
        for(int i=s-1;i<m;i++){
            for(int j=s-1;j<n;j++){
                int ts=t[i][j]-t[i-s][j]-t[i][j-s]+t[i-s][j-s];
                if(!ts){
                    ans=s;
                    f=1;
                    c=0;
                    for(int k=0;k<m;k++){
                        for(int l=0;l<n;l++)
                            temp[k][l]=a[k][l];
                    }
                    for(int k=i;k>=i-s;k--){
                        for(int l=j;l>=j-s;l--){
                            if(temp[k][l]=='P'){
                                c++;
                                Clear(k,l);
                            }
                        }
                    }
                    mc=min(c,mc);
                }
            }
            if(f)break;
        }
        if(f)break;
    }
    cout << ans*ans << " " << (mc>=INT_MAX?0:mc);

    return 0;
}
