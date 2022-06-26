#include<bits/stdc++.h>
using namespace std;
int main()
{
    char name[4][50];
    for(int i=0;i<4;i++){
        cin >> name[i];
    }
    int score[4]={0,0,0,0};
    int board[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin >> board[i][j];
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<i;j++){
            if(board[i][j]>board[j][i]){
                score[i]+=3;
            }
            if(board[i][j]<board[j][i]){
                score[j]+=3;
            }
            if(board[i][j]==board[j][i]){
                score[i]++;
                score[j]++;
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            if(score[i]<score[j]){
                char temp_n[50];
                strcpy(temp_n,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],temp_n);
                int temp_s;
                temp_s = score[i];
                score[i] = score[j];
                score[j] = temp_s;
            }
        }
    }
    int sum_a, sum_b, p_a, p_b;
    for(int i=0;i<4;i++){
        sum_a=0;
        sum_b=0;
        p_a=0;
        p_b=0;
        if(score[i]==score[i+1]){
            for(int j=0;j<4;j++){
                sum_a+= board[j][i] - board[i][j];
                sum_b+= board[j][i+1] - board[i+1][j];
                p_a += board[j][i];
                p_b += board[j][i+1];
//                cout << sum_a << " " << sum_b << endl;
            }
//            cout << sum_a << " " << sum_b << endl;
            if(sum_a < sum_b || (sum_a==sum_b && p_a < p_b)){
                char temp[50];
                strcpy(temp,name[i]);
                strcpy(name[i],name[i+1]);
                strcpy(name[i+1],temp);
            }
//            if(){
//
//            }
        }
    }
    for(int i=0;i<4;i++){
        cout << name[i] << " " << score[i] << endl;
    }
    return 0;
}

/*

  a b c d
a 0 1 2 1
b 0 0 0 1
c 2 1 0 2
c 0 1 2 0

*/
