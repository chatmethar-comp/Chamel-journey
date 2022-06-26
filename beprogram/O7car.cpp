#include<bits/stdc++.h>
using namespace std;
#define ar array
const int mxN=40;
int m, s, t, ti=-1, tj=-1, r[105][mxN+1], opt[]={-1,1,0};
queue<ar<int,2>> qu;
vector<int> ans;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> m >> s >> t;
    for(int i=0;i<t;i++){
        for(int j=0;j<m;j++){
            cin >> r[i][j];
            if(r[i][j])
                r[i][j]=-1;
        }
    }
    qu.push({-1,s-1});
    while(qu.size()){
        ar<int,2> u=qu.front();
        qu.pop();
        if(u[0]==t-1&&r[u[0]][u[1]]!=-1){
            ti=u[0],tj=u[1];
            break;
        }
        for(int i=0;i<3;i++){
            if(u[1]+opt[i]<0||u[1]+opt[i]>=m||r[u[0]+1][u[1]+opt[i]]==-1)
                continue;
            qu.push({u[0]+1,u[1]+opt[i]});
            r[u[0]+1][u[1]+opt[i]]=i+1;
        }
    }
//    cout << endl << endl;
//    for(int i=0;i<t;i++){
//        for(int j=0;j<m;j++)
//            cout << r[i][j] << "\t";
//        cout << endl;
//    }
    if(ti==-1){
        cout << -1;
        return 0;
    }

    while(tj!=s-1||ti!=-1){
        ans.push_back(r[ti][tj]);
        if(r[ti][tj]==1)
            tj++;
        else if(r[ti][tj]==2)
            tj--;
        ti--;
    }
    for(int i=ans.size()-1;i>=0;i--)
        cout << ans[i] << endl;
    return 0;
}
