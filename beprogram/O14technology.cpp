#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=1e5+1;
int n, k, t, le[mxN], di[mxN];
vector<int> adj[mxN], l[mxN];
int main()
{
    cin >> n >> k >> t;
    for(int i=1,a,p;i<=n;i++){
        cin >> a >> p;
        l[a].push_back(i);
        le[i]=a;
        for(int j=0,x;j<p;j++){
            cin >> x;
            adj[x].push_back(i);
            di[i]++;
        }
    }
//    for(int i=1;i<=n;i++){
//        cout << i << " -";
//        for(int j : adj[i])
//            cout << " " << j;
//        cout << " <- " << di[i] << " " << l[i] << endl;
//    }
    for(int i=1;i<=n;i++){
        if(di[i]==0){
            queue<int> qu;
            qu.push(i);
            while(qu.size()&&(t--)){
                int u=qu.front();
                qu.pop();
                l[le[u]].erase(find(l[le[u]].begin(),l[le[u]].end(),u));
                for(int v : adj[u]){
                    if(find(l[le[v]].begin(),l[le[v]].end(),v)!=l[le[v]].end())
                        qu.push(v);
                }
            }
            //bfs
        }
    }
    int c=0;
    for(int i=1;i<=k;i++){
        if(l[i].size()==0)
            c++;
        else
            break;
    }
    cout <<c;
    return 0;
}
