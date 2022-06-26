#include<bits/stdc++.h>
using namespace std;

void fall(char board, int x, int y, int *score){
    char breakd=false;
    if(board[x][y]==board[x][y-1]){
        board[x][y-1]='-';
        *score+=5;
        breakd=true;
    }
    if(board[x][y]==board[x][y+1]){
        board[x][y+1]='-';
        *score+=5;
        breakd=true;
    }
    if(board[x][y]==board[x+1][y]){
        board[x+1][y]='-';
        *score+=5;
        breakd=true;
    }
    if(breakd){
        board[x][y] = '-';
        *score+=5;
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    char board[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }
    int ops;
    cin >> ops;
    int x, y;
    char op;
    int score=0;
    while(ops--){
        cin >> x >> y >> op;
        if(op=='R'){
            if(y+1>n){
                score-=5;
                continue;
            }
            if(board[x][y+1]!='-'){
                score-=5;
            } else {
                board[x][y+1] = board[x][y];
                board[x][y] = '-';
                y++;
                while(board[x+1][y]=='-'){
                    board[x+1][y] = board[x][y];
                    board[x][y] = '-';
                    x++;
                }
                fall(board[m][n], x, y , &score);
            }
        }
    }
    cout << score << endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
