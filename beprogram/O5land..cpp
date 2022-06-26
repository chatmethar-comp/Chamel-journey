#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, a, di[]={-1,-1,-1,0,0,1,1,1}, dj[]={-1,0,1,-1,1,-1,0,1}, ci, cj;
int si[]={1,1,1,2,2,2,3,3,3}, sj[]={1,2,3,1,2,3,1,2,3};
double c[4][4], tc[4][4], p=0, mp=INT_MAX, mm, ans=INT_MAX;
bool vis[4][4];

void in()
{
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)
            c[i][j]=tc[i][j];
    }
}

void pr()
{
    cout <<endl;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j)
            cout << c[i][j] << "\t";
        cout <<endl;
    }

    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j)
            cout << vis[i][j] << " ";
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
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin >> tc[i][j];
            if(c[i][j]<mp)
                mp=c[i][j];//,ci=i,cj=j;
        }
    }

    for(int t=0;t<9;t++){
        cout << t << endl;memset(vis,0,sizeof(vis));
        cout << si[t] << " " << sj[t] << endl;
        in();
        if(e(si[t],sj[t])){

            ci=si[t],cj=sj[t];
            a=n*m;
            p=0;
            while(a--){
//                cout << p << " " << mp << endl;
                pr();
                p+=mp;
                vis[ci][cj]=1;
                mm=INT_MAX;
                for(int i=0;i<8;++i){
                    int ni=ci+di[i];
                    int nj=cj+dj[i];
                    if(e(ni,nj)){
        //                cout << "pass\n";
                        c[ni][nj]+=(mp*0.1);
                    }
                }
                mp=INT_MAX;
                int ii;
                int jj;
                for(int i=0;i<8;++i){
                    int ni=ci+di[i];
                    int nj=cj+dj[i];
        //            cout << ni << " " << nj << endl;
                    if(e(ni,nj)&&c[ni][nj]<mp){
        //                cout << "pass\n";
                        mp=c[ni][nj];
                        ii=ni;
                        jj=nj;
                    }
                }

                ci=ii;cj=jj;
            }
            cout << p << endl;
            ans=min(ans,p);
        }
    }

    printf("%.2lf",ans);
    return 0;
}
/*
3 3
500000 750000 1000000
500000 1200000 1000000
1000000 800000 750000
*/
