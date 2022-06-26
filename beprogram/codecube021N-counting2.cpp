#include<bits/stdc++.h>
using namespace std;
const int mxN=2e4+5, mxM=2e5+5;
struct Q{
    int v, i, a, t;
    bool operator<(const Q&o)const{
        if(v!=o.v)return v<o.v;
        return t<o.t;
    }
};
vector<Q> q;
int n, m, a, b, s, e, v;
int fen[mxN], ans[mxM];

void prfen()
{
    for(int i=0;i<=n;i++){
        cout << fen[i] << " ";
    }
    cout << endl;
}

void u(int i)
{
    while(i<=n){
        fen[i]++;
        i+=(i&-i);
        prfen();
    }
}

int solve(int i)
{
    int c=0;
    while(i>0){
        c+=fen[i];
        i-=(i&-i);
    }
    cout << endl;
    return c;
}

int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> v;q.push_back({v,i,0,-2});
    }
    for(int i=1;i<=m;i++){
        cin >> a >> b >> s >> e;
        q.push_back({s-1,a-1,i,1});
        q.push_back({s-1,b,i,-1});
        q.push_back({e,a-1,i,-1});
        q.push_back({e,b,i,1});
    }
    sort(q.begin(),q.end());
    for(auto [v,i,a,t] : q){
        if(t==-2)
            u(i);
        else
            ans[a]+=solve(i)*t;
    }
    for(int i=1;i<=m;i++)
        cout << ans[i] << " ";
    return 0;
}
