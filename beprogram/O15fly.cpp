#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=2e3;
int r, c, t=0;
vector<ar<int,4>> tr;
int fly[mxN];
int main()
{
    memset(fly,0,sizeof(fly));
    cin >> r >> c;
    for(int i=r-1,a,c;i>=0;i--){
        char b, d;
        cin >> a >> b >> c >> d;
        tr.push_back({a,(b=='R'?1:-1),c,(d=='R'?1:-1)});
    }
//    for(int i=0;i<r;i++){
//
//    }
    for(int i=0;i<1e4;i++){
        for(int j=0;j<r;j++){
            if(tr[j][0]==tr[j][2]){
                tr[j][1]*=-1;
                tr[j][3]*=-1;
            }
            tr[j]={tr[j][0]+tr[j][1],tr[j][1],tr[j][2]+tr[j][3],tr[j][3]};

            if(tr[j][0]>c){
                tr[j][0]=c-1;
                tr[j][1]*=-1;
            }
            if(tr[j][0]<0){
                tr[j][0]=1;
                tr[j][1]*=-1;
            }
            if(tr[j][2]>c){
                tr[j][2]=c-1;
                tr[j][3]*=-1;
            }
            if(tr[j][2]<0){
                tr[j][2]=1;
                tr[j][3]*=-1;
            }

        }
//        for(int j=0;j<r;j++)
//        cout << tr[j][0] << " " << tr[j][1] << " " << tr[j][2] << " "<< tr[j][3] << endl;
//        cout << endl;

        for(int j=0;j<=c;j++){
            cout << fly[j] << " " ;
            while((fly[j]<tr[fly[j]][0]||fly[j]>tr[fly[j]][2])&&fly[j]!=0){
                fly[j]--;
            }
            if(j>=tr[fly[j]][0]&&j<=tr[fly[j]][2]){
                fly[j]++;
            }
            if(fly[j]==r){
                cout << i << endl;
                return 0;
            }
        }
//        cout << endl;

    }
    return 0;
}
