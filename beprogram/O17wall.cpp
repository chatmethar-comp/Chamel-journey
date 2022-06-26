#include<bits/stdc++.h>
using namespace std;
#define ar array
int r, c, vis[1010][1010], mx=INT_MIN;
int di[]={-1,0,1,0}, dj[]={0,-1,0,1};
string a[1010];
queue<ar<int,2>> qu;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(vis,0,sizeof(vis));
    cin >> r >> c;
    for(int i=0;i<r;i++){
        cin >> a[i];
    }
    qu.push({1,1});
    while(qu.size()){
        int i=qu.front()[0];
        int j=qu.front()[1];
        qu.pop();
        if(vis[i][j])
            continue;
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int ni=i+di[k], nj=j+dj[k];
            if(ni<0||ni>=r||nj<0||nj>=c||a[ni][nj]=='X')
                continue;
            a[ni][nj]='F';
            qu.push({ni,nj});
        }
    }
    memset(vis,0,sizeof(vis));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(a[i][j]=='X'){
                int cc=0;
                qu.push({i,j});
                while(qu.size()){
                    int x=qu.front()[0];
                    int y=qu.front()[1];
//                    cout << x << " " << y << " " << vis[x][y] << endl;
                    qu.pop();
                    if(vis[x][y])
                        continue;
                    vis[x][y]=1;
                    if(a[x][y]=='X'){
                        for(int k=0;k<4;k++){
                            int nx=x+di[k], ny=y+dj[k];
//                            cout << nx << " " << ny << " " << a[nx][ny] << "  " << cc << endl;
                            if(nx<0||nx>=r||ny<0||ny>=c||a[nx][ny]!='F')
                                continue;
                            cc++;

                        }
                    }
                    for(int k=0;k<4;k++){
                        int nx=x+di[k], ny=y+dj[k];
                        if(nx<0||nx>=r||ny<0||ny>=c||a[nx][ny]!='X')
                            continue;
                        qu.push({nx,ny});
                    }

                }
                mx=max(mx,cc);
            }
        }
    }
    cout << mx;
//    for(int i=0;i<r;i++){
//        for(int j=0;j<c;j++){
//            cout << a[i]
//        }
//    }
    return 0;
}
/*
4 6
......
.X.X..
.X.XX.
......
8

8 7
.......
.XXXXX.
.X...X.
.X.X.X.
.X.X.X.
.X...X.
.XXXXX.
.......
22
*/
