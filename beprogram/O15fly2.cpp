/*
  [credit]
user: Nepumi
submitted at: 26/11/2563 14:19:58
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=2e3+1;
int n, m;
queue<ar<int,2>> qu;
ar<int,2> mp[mxN*2][mxN*2], fly[mxN*2][mxN*2];
bool alive[mxN*2][mxN*2];
int main()
{
    cin >> n >> m;
    for(int i=0;i<=2*m;i++)
        mp[i][0]={0,m};
    for(int i=1,a,c;i<=n;i++){
        char b, d;
        cin >> a >> b >> c >> d;
        for(int j=0;j<=2*m;j++){
            int l=min(a,c), r=max(a,c);
            mp[j][i]={min(a,c)+1,max(a,c)-1};
            if(b=='R'){
                if(a==m){
                    a--;
                    b='L';
                } else {
                    a++;
                }
            } else {
                if(a==0){
                    a++;
                    b='R';
                } else {
                    a--;
                }
            }
            if(d=='R'){
                if(c==m){
                    c--;
                    d='L';
                } else {
                    c++;
                }
            } else {
                if(c==0){
                    c++;
                    d='R';
                } else {
                    c--;
                }
            }
        }
//        for(int i=0;i<=m*2.5;i++){
//        for(int j=0;j<=m;j++){
//            cout << mp[i][j][0] << " " << mp[i][j][1] << "\t";
//        }
//        cout << endl;
//    }
    }
    for(int i=0;i<m*2;i++)for(int j=0;j<=n;j++)fly[i][j] = {m*2,0};
    fly[0][0] = {0,m};
    qu.push({0,0});
    while(qu.size()){
        int time, level, L, R;
        time=qu.front()[0];
        level=qu.front()[1];
        L=fly[time%(2*m)][level][0];
        R=fly[time%(2*m)][level][1];
        qu.pop();
        alive[time%(2*m)][level]=0;
        if(level==n){
            cout << time+1;
            return 0;
        }

        int ntime=(time+1)%(2*m);
        int nL=max(L,mp[ntime][level+1][0]);
        int nR=min(R,mp[ntime][level+1][1]);
        if(nL<=nR){
            if(nL<fly[ntime][level+1][0]||fly[ntime][level+1][1]<nR){
                fly[ntime][level+1][0]=min(fly[ntime][level+1][0],nL);
                fly[ntime][level+1][1]=max(fly[ntime][level+1][1],nR);
                if(!alive[ntime][level+1]){
                    alive[ntime][level+1]=1;
                    qu.push({time+1,level+1});
                }
            }
        }
        nL=max(L,mp[ntime][level][0]);
        nR=min(R,mp[ntime][level][1]);
        if(nL<=nR){
            if(nL<fly[ntime][level][0]||fly[ntime][level][1]<nR){
                fly[ntime][level][0]=min(fly[ntime][level][0],nL);
                fly[ntime][level][1]=max(fly[ntime][level][1],nR);
                if(!alive[ntime][level]){
                    alive[ntime][level]=1;
                    qu.push({time+1,level});
                }
            }
        }
    }
    return 0;
}
