#include<bits/stdc++.h>
using namespace std;
char room[1005][1005];
int movex[] = {-1,0,0,1};
int movey[] = {0,-1,1,0};

void clear_room(int i, int j)
{
    room[i][j]='#';
    for(int k=0;k<4;k++){
        if(room[i+movey[k]][j+movex[k]] == '.'){
            clear_room(i+movey[k], j+movex[k]);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> room[i][j];
        }
    }
    long long count_room =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(room[i][j]=='.'){
                count_room++;
                clear_room(i,j);
            }
        }
    }
    cout << count_room << endl;
    return 0;
}
