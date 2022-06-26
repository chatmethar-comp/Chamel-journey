#include<bits/stdc++.h>
using namespace std;
int r, c, a, b, ans[400][400];
char opr;
int U[40010], D[40010], L[40010], R[40010];
bool p=0;

void dfs(int now, int i, int j)
{
    ans[i][j]=now;
    if(U[now]!=-1&&ans[i-1][j]==-1)
        dfs(U[now],i-1,j);
    if(D[now]!=-1&&ans[i+1][j]==-1)
        dfs(D[now],i+1,j);
    if(L[now]!=-1&&ans[i][j-1]==-1)
        dfs(L[now],i,j-1);
    if(R[now]!=-1&&ans[i][j+1]==-1)
        dfs(R[now],i,j+1);
}

int main()
{
    memset(U,-1,sizeof(U));
    memset(D,-1,sizeof(D));
    memset(L,-1,sizeof(L));
    memset(R,-1,sizeof(R));
    memset(ans,-1,sizeof(ans));
    cin >> r >> c;
    for(int i=0;i<r*c-1;i++){
        cin >> a >> opr >> b;
        if(opr=='U'){
            U[b]=a;D[a]=b;
        }
        if(opr=='L'){
            L[b]=a;R[a]=b;
        }
    }
    dfs(0,r,c);
    for(int i=0;i<400;i++){
        for(int j=0;j<400;j++){
            if(ans[i][j]!=-1){
                for(int k=i;k<i+r;k++){
                    for(int l=j;l<j+c;l++){
                        cout << ans[k][l] << " ";
                    }
                    cout << endl;
                }
                p=1;
                break;
            }
        }
        if(p)
            break;
    }

//    cout << endl << endl;
//    for(int i=0;i<30;i++){
//        for(int j=0;j<30;j++){
//            cout << ans[i][j] << " ";
//        }
//        cout << endl;
//    }
    return 0;
}
