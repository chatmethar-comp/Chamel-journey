#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=1e3, di[]={1,0,-1,0}, dj[]={0,1,0,-1};
const char dc[]={'D','R','U','L'};
int n, m, si, sj, d1[mxN][mxN], d2[mxN][mxN], p1[mxN][mxN], p2[mxN][mxN];
string s[mxN], p[mxN];
bool vis[mxN][mxN];

bool e(int i, int j)
{
    return i>=0&&i<n&&j>=0&&j<m&&s[i][j]=='.'&&!vis[i][j];
}

void bfs(vector<ar<int,2>> v1, int d[mxN][mxN], int p[mxN][mxN])
{
    queue<ar<int,2>> qu;
    qu.push({si,sj});
    memset(vis, 0,sizeof(vis));
    memset(d, 0x3f, sizeof(d));
    for(ar<int,2> a : v1){
        qu.push(a);
        vis[a[0]][a[1]]=1;
    }
    while(qu.size()){
        ar<int,2> u=qu.front();
        qu.pop();
        for(int k=0;k<4;++k){
            int ni=u[0]+d[k], nj=u[1]+d[k];
            if(!e(ni,nj))
                continue;
            qu.push({ni,nj});
            vis[ni][nj]=1;
            d[ni][nj]=d[u[0]][u[1]]+1;
            p[ni][nj]=k;
        }
    }
}

int main()
{
    cin >> n >> m;
    vector<ar<int,2>> v2;
    for(int i=0;i<n;++i){
        cin>>s[i];
        for(int j=0;j<m;++j){
            if(s[i][j]=='A')
                si=i,sj=j,s[i][j]='.';
            if(s[i][j]=='M')
                v2.push_back({i,j}),s[i][j]='.';
        }
        p[i]=string(m,0);
    }
    bfs({si,sj}, d1, p1);
    bfs(v2, d2, p2);
    int ti=-1, tj;
    for(int i=0;i<n;++i){

    }
    if(p[ti])
}
