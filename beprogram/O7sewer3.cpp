#include<bits/stdc++.h>
using namespace std;
#define ar array
int r, c, d[200][200];
int di[]={-1,0,1,0}, dj[]={0,-1,0,1};
char a[200][200];
queue<ar<int,3>> qu;
int main()
{
    memset(d,0,sizeof(d));
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> r >> c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> a[i][j];
        }
    }
    qu.push({1,1,1});
    d[1][1]=1;
    while(qu.size()){
        int i=qu.front()[0];
        int j=qu.front()[1];
        int t=qu.front()[2];
//        cout << i << " " << j << " " << a[i][j] << endl;
        qu.pop();
        for(int k=0;k<4;k++){
            int ni=i+di[k];
            int nj=j+dj[k];
            if(ni<1||ni>r||nj<1||nj>c)
                continue;
            if(di[k]==-1&&(a[ni][nj]=='R'||a[ni][nj]=='N'))
                continue;
            if(di[k]==1&&(a[i][j]=='R'||a[i][j]=='N'))
                continue;
            if(dj[k]==-1&&(a[ni][nj]=='D'||a[ni][nj]=='N'))
                continue;
            if(dj[k]==1&&(a[i][j]=='D'||a[i][j]=='N'))
                continue;
//            cout << d[ni][nj] << endl;
            if(d[ni][nj]==t+1){
                cout << t+1 << endl << ni << " " << nj;
                return 0;
            }
            else if(!d[ni][nj]){
                d[ni][nj]=t+1;
                qu.push({ni,nj,t+1});
            }

        }
    }
    return 0;
}
