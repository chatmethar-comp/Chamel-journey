#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int celebrity(vector<vector<int>> M, int n)
    {
        int a=0;
        int b=n-1;
        while(a<b){
            if(M[a][b]){
                a++;
            } else {
                b--;
            }
        }
        for(int i=0;i<n;i++){
            if((i!=a) && (M[i][a]==0 || M[a][i]==1)){
                return -1;
            }
        }
        return a;
    }

};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> M(n, vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> M[i][j];
        }
    }
    Solution ob;
    cout << ob.celebrity(M,n) << endl;
    return 0;
}
