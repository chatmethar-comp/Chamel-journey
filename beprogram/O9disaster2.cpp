#include<bits/stdc++.h>
using namespace std;
int n;
int edges[30][30], temp[30][30];
vector<int> ans;
bool w;
string p;
void dfs(int n)
{
    ans.push_back(n);
    for(int i=0;i<30;i++){
        if(temp[n][i]>0){
            temp[n][i]--;
            temp[i][n]--;
            dfs(i);
            break;
        }
    }
}
int main()
{
    memset(edges,0,sizeof(edges));
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> p;
        edges[p[0]-'A'][p[1]-'A']++;
        edges[p[1]-'A'][p[0]-'A']++;
    }
    for(int i=0;i<30;i++){
        w=1;
        ans.clear();
        for(int j=0;j<30;j++)
            for(int k=0;k<30;k++)
                temp[j][k]=edges[j][k];
        dfs(i);
        if(ans.size()!=n+1)
            continue;
        for(int j=0;j<30;j++){
            for(int k=0;k<30;k++){
                if(temp[j][k]!=0){
                    w=0;break;
                }
            }
        }
        if(w){
            for(int a : ans)
                cout << (char)(a+'A') << " ";
            break;
        }
    }
    return 0;
}
