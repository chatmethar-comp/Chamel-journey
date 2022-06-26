#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n, -1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> graph[i][j];
            if(i==j)
                graph[i][j]=1;
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                graph[i][j]=graph[i][j]||(graph[i][k]&&graph[k][j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
