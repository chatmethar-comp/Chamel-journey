#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

queue<pair<string, pair<int,int>>> q;
pair<string, pair<int,int>> walk;
int starti, startj;
int endi, endj;

const int di[4]={1,0,-1,0}, dj[4]={0,1,0,-1};
const char dc[4]={'D','R','U','L'};
const int mxn=1e3;
string room[mxn], p[mxn];
int n, m, d[mxn][mxn];

bool floor(int i, int j)
{
    return i>=0&&i<n&&j>=0&&j<m&&room[i][j]=='.';
}

int main()
{

    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> room[i];
        for(int j=0;j<m;j++){
            if(room[i][j]=='A')
                starti=i, startj=j;// room[i][j]='.';
            if(room[i][j]=='B'){
                endi=i, endj=j, room[i][j]='.';
            }
        }
        p[i]=string(m,0);
    }
//    cout << p;
    queue<array<int, 2>> q;
    q.push({starti, startj});

    while(q.size()){
        array<int, 2> u=q.front();
        q.pop();
        room[u[0]][u[1]]='#';
        for(int k=0;k<4;k++){
            int ni=u[0]+di[k], nj=u[1]+dj[k];

            if(!floor(ni,nj))
                continue;
            q.push({ni,nj});
            room[ni][nj]='#';
            d[ni][nj]=k;
            p[ni][nj]=dc[k];
        }
    }
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            cout << p[i][j];
//        }
//        cout << endl;
//    }
    if(p[endi][endj]){
        cout << "YES\n";
        string t;
        while(endi!=starti||endj!=startj){
            t+=p[endi][endj];
            int dd=d[endi][endj]^2;
            endi+=di[dd];
            endj+=dj[dd];
        }
        reverse(t.begin(),t.end());
        cout << t.length() << endl;
        cout << t << endl;
    } else {
        cout << "NO\n";
    }



    return 0;
}
/*
5 8
########
#.A#...#
#.##.#B#
#......#
########
*/
