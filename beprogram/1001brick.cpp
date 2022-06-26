#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    char game[n][m];
    int brick;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> game[i][j];
        }
    }
    bool place=0;
    for(int i=0;i<m;i++){
        place=0;
        cin >> brick;
        for(int j=0;j<n&&brick!=0;j++){
            if(game[j][i]=='O' || game[j][i]=='#'){
                game[j-1][i]='#';
                place=1;
                brick--;
                j=j-2;
            }
        }
        if(!place)
        {
            for(int j=0;j<brick;j++){
                game[n-1-j][i]='#';
            }
        }

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << game[i][j];
        }
        cout << endl;
    }
    return 0;
}
