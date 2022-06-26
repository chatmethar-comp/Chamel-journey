#include<bits/stdc++.h>
using namespace std;

int w, h;
char c[100][100];
bool a[100][100];
void pond(int x, int y)
{
    if(x<h&&c[x+1][y]=='P' && a[x+1][y]==false){
        a[x+1][y]=true;
        pond(x+1,y);
    }
    if(y<h&&c[x][y+1]=='P' && a[x][y+1]==false){
        a[x][y+1]=true;
        pond(x,y+1);
    }
    if(x>1&&c[x-1][y]=='P' && a[x-1][y]==false){
        a[x-1][y]=true;
        pond(x-1,y);
    }
    if(y>1&&c[x][y-1]=='P' && a[x][y-1]==false){
        a[x][y-1]=true;
        pond(x,y-1);
    }
}

int main()
{
    cin >> w >> h;
    char area[h][w];
    int k=min(w,h);
    int ans=INT_MAX;
    int ch=0;
    int t;
    cout << h << endl;
    for(int i=1;i<=h;i++){
        scanf("%s", &c[i][1]);
    }
    for(t=k;t>=1;t--){
        cout << t << endl;
        int rols=h-t+1;
        int cols=w-t+1;
        for(int i=1;i<=rols;i++){
            for(int j=1;j<=cols;j++){
                cout << t << " " << i << " " << j << endl;
                int p=0;
                int r=1;
                for(int x=i;x<i+t && r==1;x++){
                    for(int y=j;y<j+t && r==1;y++){
                        if(c[x][y]=='T'){
                            r=0;
                        }
                        else if(c[x][y]=='P' && a[x][y]==0){
                            // when found pool check all area of pool;
                            p++;
                            a[x][y]=true;
                            pond(x,y);
                        }
                    }
                }
                for(int x=1;x<=h;x++){
                    for(int y=1;y<=w;y++){
                        a[x][y]=false;
                    }
                }
                if(r==0){
                    continue;
                }
                ans = min(ans,p);
                ch=1;
            }
        }
        if(ch){
            break;
        }
    }
    if(ch)
    {
        cout << t*t << " " << ans;
    }
    else {
        cout << "0 0";
    }
    return 0;
}

/*
8 6
SSSSSSSS
SSSSSSSS
SPPSSSSS
SSSPSSSS
SSSSSTTS
PSSSSTSS

25 2
*/
