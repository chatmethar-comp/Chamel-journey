#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=1e3+5;
int n, m, si, sj, di[]={-1,0,1,0}, dj[]={0,-1,0,1}, mw[mxN][mxN];
char d[]={'U','L','D','R'};
char p[mxN][mxN], s[mxN][mxN];
vector<char> ans;
vector<ar<int,2>> m;
queue<ar<int,2>> q, qm;
ar<int,2> u;
int main()
{
    memset(mw,0,sizeof(mw));
    cin >> n >> m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin >> p[i][j];
            if(p[i][j]=='A')
                si=i,sj=j;
            if(p[i][j]=='M')
                m.push_back({i,j});
        }
    }
    for(ar<int,2> v:m){
        qm.push({v[0],v[1]});
        while(qm.size()){

        }
    }
    q.push({si,sj});
    while(q.size()){
        u=q.front();
        q.pop();
        if(u[0]==n-1||u[0]==0||u[1]==m-1||u[1]==0){
            break;
        }
        for(int i=0;i<4;++i){
            int ni=u[0]+di[i];
            int nj=u[1]+dj[i];
            if(p[ni][nj]=='.'){
                p[ni][nj]='x';
                q.push({ni,nj});
                s[ni][nj]=d[i];
            }
        }
    }
    if(u[0]!=n-1&&u[0]!=0&&u[1]!=m-1&&u[1]!=0){
        cout << "NO";
    } else {
        cout << "YES\n";
        int i=u[0], j=u[1];
        while(i!=si||j!=sj){
            ans.push_back(s[i][j]);
            if(s[i][j]=='U')
                i++;
            else if(s[i][j]=='L')
                j++;
            else if(s[i][j]=='D')
                i--;
            else if(s[i][j]=='R')
                j--;
        }
        reverse(ans.begin(),ans.end());
        cout << ans.size() << endl;
        for(char d:ans){
            cout << d;
        }
    }
//    for(int i=0;i<n;++i){
//        for(int j=0;j<m;++j){
//            cout << s[i][j];
//        }
//        cout << endl;
//    }
    return 0;
}

/*
5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######
*/
