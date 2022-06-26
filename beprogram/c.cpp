#include<bits/stdc++.h>
using namespace std;
int u[40010], d[40010], l[40010], r[40010];
int r, c, a, b, ans[400][400];
char opr;

void dfs(int now, int i, int j)
{
    ans[i][j]=now;
    if(u[now]!=-1&&ans[i-1][j]==-1)
        dfs(u[now],i-1,j);
    if(l[now]!=-1&&ans[i+1][j]==-1)
        dfs(d[now],i+1,j);
    if(l[now]!=-1&&ans[i][j-1]==-1)
        dfs(l[now],i,j-1);
    if(l[now]!=-1&&ans[i][j+1]==-1)
        dfs(l[now],i,j+1);
}

int main()
{
    memset(u,-1,sizeof(u));
    memset(d,-1,sizeof(d));
    memset(l,-1,sizeof(l));
    memset(r,-1,sizeof(r));
    memset(ans,-1,sizeof(ans));
    cin >> r >> c;
    for(int i=0;i<r*c-1;i++){
        cin >> a >> opr >> b;
        if(opr=='U')
            u[b]=a, d[a]=b;
        if(opr=='L')
            l[b]=a, r[a]=b;
    }
    dfs(0,r,c);
    for(int i=0;i<400;i++){
        for(int j=0;j<400;j++){
            if(ans[i][j]!=-1){
                for(int k=i;k<i+r;k++){
                    for(int l=j;l<j+c;j++){
                        cout << ans[i][j] << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
    return 0;
}
