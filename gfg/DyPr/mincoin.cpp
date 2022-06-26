#include<bits/stdc++.h>
using namespace std;
int mincoin(int coins[], int m, int v)
{
    int table[v+1];
    table[0]=0;
    for(int i=1;i<=v;i++){
        table[i]=INT_MAX;
    }
    for(int i=1;i<=v;i++){
        for(int j=0;j<m;j++){
            if(coins[j]<=i){
                int sub_res = table[i-coins[j]];
                if(sub_res!=INT_MAX && sub_res+1<table[i]){
                    table[i]=sub_res+1;
                }
            }
        }
    }
    if(table[v]==INT_MAX){
        return -1;
    }
    return table[v];
}
int main()
{
    int coins[] = {9,6,5,1};
    int m = sizeof(coins)/sizeof(coins[0]);
    int v = 11;
    cout << "minimum coin required is " << mincoin(coins, m, v);
    return 0;
}
