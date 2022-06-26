#include<bits/stdc++.h>
using namespace std;
#define ar array
int r, c, obj=0, steps=0;
int di[]={-1,0,0,1};
int dj[]={0,-1,1,0};
char a[2005][2005];
bool vis[2005][2005];
queue<ar<int,3>> bfs;
bool e(int i, int j)
{
    return i>=0&&i<r&&j>=0&&j<c&&!vis[i][j];
}
int main()
{
    memset(vis, 0, sizeof(vis));
    cin >> r >> c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> a[i][j];
            if(a[i][j]=='X'){
                bfs.push({0,i,j});
                vis[i][j]=1;
            }
        }
    }
    while(bfs.size()){
        int u=bfs.front()[1];
        int v=bfs.front()[2];
        int st=bfs.front()[0];
        bfs.pop();
        for(int i=0;i<4;i++){
            int ni=u+di[i], nj=v+dj[i];
            if(e(ni,nj)&&a[ni][nj]!='W'){
                vis[ni][nj]=1;
                if(a[ni][nj]=='A'){
                    obj++;
                    steps+=2*(st+1);
                }
                bfs.push({st+1,ni,nj});
            }
        }
    }
    cout << obj << " " << steps;
    return 0;
}
