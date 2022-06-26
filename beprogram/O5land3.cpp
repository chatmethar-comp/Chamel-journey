#include<bits/stdc++.h>
using namespace std;
double l[5][5], ans=INT_MAX, price;
int p[]={0,1,2,3,4,5,6,7,8}, n, m;
int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin >> l[i][j];
    }
    do
    {
        double land[5][5];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                land[i][j]=l[i][j];
            }
        }
        price=0;
        for(int i=0;i<n*m;i++){
            int r=p[i]/m, c=p[i]%m;
            price+=land[r][c];
            for(int j=-1;j<=1;j++){
                for(int k=-1;k<=1;k++){
                    if(j==0&&k==0)
                        continue;
                    if(r+j<0||r+j>=n||c+k<0||c+k>=m)
                        continue;
                    land[r+j][c+k]+=land[r][c]*0.1;
                }
            }
        }
        ans=min(ans,price);
    }while(next_permutation(p,p+n*m));
    printf("%.2lf", ans);
    return 0;
}
