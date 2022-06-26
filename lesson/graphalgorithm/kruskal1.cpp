#include<bits/stdc++.h>
using namespace std;
class DSU{
    int* parent;
    int* rank;
public:
    DSU(int n){
        parent=new int[n];
        rank=new int[n];
        for(int i=0;i<n;i++){
            parent[i]=-1;
            rank[i]=1;
        }
    }
    int find(int i){
        if(parent[i]==-1)
            return i;
        return parent[i]=find(parent[i]);
    }
    void unite(int x, int y)
    {
        int s1=find(x);
        int s2=find(y);
        if(s1!=s2){
            if(rank[s1]<rank[s2]){
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            } else {
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
        }
    }
};
int main()
{
    vector<pair<int,pair<int,int>>> edgelist;
    int n, e;
    cin >> n >> e;
    for(int i=0;i<e;++i){
        int w,s,d;
        cin >> w >> s >> d;
        edgelist.push_back({w,{s,d}});
    }
    DSU s(n);
    sort(edgelist.begin(),edgelist.end());
    for(auto edge:edgelist){
        int u, v, w;
        u=edge.second.first;
        v=edge.second.second;
        w=edge.first;
        if(s.find(u)!=s.find(v)){
            s.unite(u,v);
            cout << u << " -- " << v << endl;
        }
    }
    return 0;
}
