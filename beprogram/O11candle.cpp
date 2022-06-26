#include<bits/stdc++.h>
using namespace std;
#define ar array
char a[2005][2005];
int r, c, ans=0;
int di[]={-1,-1,-1,0,0,1,1,1};
int dj[]={-1,0,1,-1,1,-1,0,1};
queue<ar<int,2>> bfs;

//bool e(int i, int j)
//{
//    return i>=0&&i<r&&j>0&&j<c;
//}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> r >> c;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin >> a[i][j];

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(a[i][j]=='1'){
                ans++;
                bfs.push({i,j});
                a[i][j]='0';
                while(bfs.size()){
                    int u=bfs.front()[0];
                    int v=bfs.front()[1];
                    bfs.pop();
                    for(int k=0;k<8;k++){
                        int ni=u+di[k];
                        int nj=v+dj[k];
//                        if(e(ni,nj)&&a[ni][nj]=='1')
//                        {
//                            a[ni][nj]='0';
//                            bfs.push({ni,nj});
//                        }
                        if(ni<0||ni>=r||nj<0||nj>=c)
                            continue;
                        if(a[ni][nj]!='1')
                            continue;
                        a[ni][nj]='0';
                        bfs.push({ni,nj});
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
