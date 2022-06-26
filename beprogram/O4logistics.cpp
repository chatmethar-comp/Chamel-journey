#include<bits/stdc++.h>
using namespace std;
#define ar array
int n, e, l, ch='Y'-'a'+1;
vector<ar<int,2>> adj[100];
queue<int> q;
vector<double> ans;
vector<int> v;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        int c;char a, b;
        cin >> a >> b >> c;
        if(a=='X')
            adj[0].push_back({b-'a'+1,c});
        else if(a!='Y')
            adj[a-'a'+1].push_back({b-'a'+1,c});
        if(b=='X')
            adj[0].push_back({a-'a'+1,c});
        else if(b!='Y')
            adj[b-'a'+1].push_back({a-'a'+1,c});
    }
//    for(int i=0;i<100;i++){
//        cout << i;
//        for(ar<int,2> u : adj[i])
//            cout << "  " << u[0] << ", " << u[1];
//        cout << endl;
//    }
    q.push(0);
    int k=0;
    while(q.size()){
        if(q.front()==ch)
            break;
        int t=q.front();
        q.pop();
        if(t==0)
            ans.push_back('X'-'a'+1);
        else
            ans.push_back(t);
        for(ar<int,2> x : adj[t]){
            if(k!=x[0]&&x[0]!=ch-1){
                v.push_back(x[1]);
                e=x[0];
            }
        }
        sort(v.begin(), v.end());
        if(e==l)
            break;
        q.push(e);
        ans.push_back(e);
        if(v.size()%2)
            ans.push_back((double)v[v.size()/2]);
        else
            ans.push_back((double)(v[v.size()/2]+v[v.size()/2-1])/2.0);
        v.clear();
        k=t;l=e;
    }

    if(q.empty())
        cout << "broken";
    else{
        double cost=0;
        reverse(ans.begin(),ans.end());
        while(ans.size()){
            cout << (char)(ans.back()+'a'-1) << " ";
            ans.pop_back();
            cout << (char)(ans.back()+'a'-1) << " ";
            ans.pop_back();
            printf("%.1lf\n", ans.back());
            cost+=ans.back();
            ans.pop_back();
        }
        printf("%.1lf",cost);
    }
    return 0;
}
