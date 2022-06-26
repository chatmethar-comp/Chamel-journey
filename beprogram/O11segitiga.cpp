#include<bits/stdc++.h>
using namespace std;
const int mxN=256;
#define ar array
int stg[3][3]={{2,1,0},{2,1,1},{1,2,1}};
int n;
string s;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=20;
    while(t--){
        cin >> n >> s;
        ar<bool,3> dp[256][256];
        if(s[0]!='0'){
            cout << "no\n";
            continue;
        }
        for(int i=0;i<n;i++)
            dp[i][i][s[i]-'0']=1;
        for(int sz=1;sz<n;sz++){
            for(int l=0;l+sz<n;l++){
                int r=l+sz;
                for(int m=l;m<r;m++){
                    for(int a=0;a<3;a++){
                        if(!dp[l][m][a])
                            continue;
                        for(int b=0;b<3;b++){
                            if(!dp[m+1][r][b])
                                continue;
                            dp[l][r][stg[a][b]]=1;
                        }
                    }
                }
            }
        }
        cout << (dp[0][n-1][0]?"yes\n":"no\n");
    }
    return 0;
}
