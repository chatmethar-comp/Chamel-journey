#include<bits/stdc++.h>
using namespace std;

bool tile[20];


int main()
{
    memset(tile,false,sizeof(tile));
    int n;
    cin >> n;
    int floor[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> floor[i][j];
        }
    }
    int correct=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!tile[floor[i][j]] && i+1<n&&j+1<n &&floor[i][j]==floor[i][j+1] && floor[i][j]==floor[i+1][j] && floor[i][j]!=floor[i+1][j+1]){
                correct++;
                tile[floor[i][j]]=true;
            } else if(!tile[floor[i][j]] && i+1<n&&j-1>=0 && floor[i][j]==floor[i+1][j] && floor[i][j] == floor[i][j-1] && floor[i][j]!=floor[i+1][j-1]){
                correct++;
                tile[floor[i][j]]=true;
            } else if (!tile[floor[i][j]] && i-1>=0&&j-1>=0&& floor[i][j]==floor[i][j-1] && floor[i][j] == floor[i-1][j] && floor[i][j]!=floor[i-1][j-1]){
                correct++;
                tile[floor[i][j]]=true;
            } else if (!tile[floor[i][j]] && i-1>=0&&j+1<n&& floor[i][j]==floor[i-1][j] && floor[i][j] == floor[i][j+1] && floor[i][j]!=floor[i-1][j+1]){
                correct++;
                tile[floor[i][j]]=true;
            }
        }
    }
    cout << correct;
    return 0;
}
