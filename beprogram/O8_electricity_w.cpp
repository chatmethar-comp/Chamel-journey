#include<bits/stdc++.h>
using namespace std;
int station[500005];
int selects[500005];
int main()
{
    int n, k;
    cin >> n >> k;
    int i, j;
    for(i=1;i<=n;i++){
        cin >> station[i];
    }
    selects[1]=station[1];
    list<pair<int,int>> q;
    q.push_back({selects[1],1});

    for(i=2;i<=n;i++){
//        for(pair<int,int> que: q){
//            cout << que.first << " " << que.second << "   " ;
//        }
//        cout << endl;
        while(!q.empty() && i-q.front().second > k){
                //
            q.pop_front();
        }
        selects[i] = q.front().first + station[i];
        while(!q.empty() && q.back().first > selects[i]){
            q.pop_back();
        }
        q.push_back({selects[i],i});
    }
    cout << selects[n];
    return 0;
}
