#include<bits/stdc++.h>
using namespace std;
int n, m, ci, cj, t;
double p[5][5], pp[5][5], ta, cp, ans=INT_MAX;
int di[]={-1,-1,-1,0,0,1,1,1};
int dj[]={-1,0,1,-1,1,-1,0,1};
bool vis[5][5];

void reset()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            p[i][j]=pp[i][j];
}

void pr()
{
    cout << endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cout << p[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

bool e(int i, int j)
{
    return i>=1&&i<=n&&j>=1&&j<=m&&!vis[i][j];
}

int main()
{
    cin >> n >> m;
    t=n*m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> pp[i][j];
        }
    }
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            memset(vis,0,sizeof(vis));
            reset();
            if(e(i,j)){
                ci=i;
                cj=j;
                cp=p[ci][cj];

                ta=0;
                for(int ts=0;ts<t;ts++){
//                    cout << "ta : " << ta << endl;
                    vis[ci][cj]=1;
                    ta+=p[ci][cj];
                    for(int k=0;k<8;++k){
                        int ni=ci+di[k], nj=cj+dj[k];
                        if(e(ni,nj)){
                            p[ni][nj]+=cp*0.1;
                        }
                    }
                    cp=INT_MAX;
                    int ii, jj;
                    for(int k=0;k<8;++k){
                        int ni=ci+di[k], nj=cj+dj[k];
//                        cout << ci << " " << cj << "  " << ni << " " << nj << endl;;
                        if(e(ni,nj)&&p[ni][nj]<cp){
//                            cout << "pass\n";
                            cp=p[ni][nj];
                            ii=ni,jj=nj;
                        }
                    }
                    ci=ii,cj=jj;
//                    pr();
//                    cout << ta << endl;
                }
//                cout << ta << endl;
                ans=min(ans,ta);
            }
        }
    }
    printf("%.2lf", ans);
    return 0;
}

/*
3 3
500000 750000 1000000
500000 1200000 1000000
1000000 800000 750000

9086505.00
*/
