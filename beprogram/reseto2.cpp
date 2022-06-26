#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int count=0;
    bool arr[n-1];
    for(int i=0;i<n-1;i++){
        *(arr+i) = true;
    }
    for(int i=2;i<=n;i++){
        for(int j=i;j<=n;j+=i){
//            cout << j << " " << arr[j-2] << endl;
            if(arr[j-2]==true){
                arr[j-2]=false;
                count++;
            }
            if(count==k){
                cout << j;
                return 0;
            }
        }
    }
}
