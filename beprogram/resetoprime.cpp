#include<bits/stdc++.h>
using namespace std;
bool p[1000];
int main(){
    int n, k;
    int count=0;

    cin >> n >> k;
    for(int i=2;i<=n;i++){
        p[i]=true;
    }
    for(int i=2;i<=n;i++){
        if(!p[i]){
            continue;
        }
        for(int j=i;j<=n;j+=i){
            if(!p[j]){
                continue;
            }
            p[j]=false;
            count++;
            if(count == k){
                cout << j;
                return 0;
            }
        }
    }
    return 0;
}
