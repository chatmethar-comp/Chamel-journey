#include<bits/stdc++.h>
using namespace std;
int main()
{
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
            if(i+1<n&&j+1<n &&floor[i][j]==floor[i][j+1] && floor[i][j]==floor[i+1][j] && floor[i][j]!=floor[i+1][j+1] && j+2!=n){
                correct++;
            } else if(i+1<n&&j-1>=0 && floor[i][j]==floor[i+1][j] && floor[i][j] == floor[i][j-1] && floor[i][j]!=floor[i+1][j-1]){
                correct++;
                if(i==0 && j==n-1){
                    correct--;
                }
            } else if (i-1>0&&j-1>=0&& floor[i][j]==floor[i][j-1] && floor[i][j] == floor[i-1][j] && floor[i][j]!=floor[i-1][j-1] ){
                correct++;
            } else if (i-1>=0&&j+1<n&& floor[i][j]==floor[i-1][j] && floor[i][j] == floor[i][j+1] && floor[i][j]!=floor[i-1][j+1]){
                correct++;

            }
        }
    }
    cout << correct;
    return 0;
}
