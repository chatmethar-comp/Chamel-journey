#include<bits/stdc++.h>
using namespace std;
#define ar array
int r, c, i, j, k;
char a[105][105], sp;
int vis[105][105];
queue<ar<int,3>> qu;
int main()
{
    memset(vis,0,sizeof(vis));
    cin >> r >> c;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            cin >> a[i][j];

    qu.push({0,0,0});
    vis[0][0]++;
    while(qu.size()){
        i=qu.front()[0];
        j=qu.front()[1];
        k=qu.front()[2];
        qu.pop();
        if(vis[i][j]==2){
            break;
        }
        if(a[i][j]=='R'||a[i][j]=='B'){
            qu.push({i,j+1,k+1});
            vis[i][j+1]++;
        }
        if(a[i][j]=='D'||a[i][j]=='B'){
            qu.push({i+1,j,k+1});
            vis[i+1][j]++;
        }
//        if(a[i-1][j]=='D'||a[i-1][j]=='B'){
//            qu.push({i-1,j,k+1});
//            vis[i-1][j]++;
//        }
//        if(a[i][j-1]=='R'||a[i][j-1]=='B'){
//            qu.push({i,j-1,k+1});
//            vis[i][j-1]++;
//        }
    }
    cout << k+1 << endl << i+1 << " " << j+1;
    return 0;
}
