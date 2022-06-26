#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int left, top, right;
    int maxright=0;
    int arr[260]={0};
    while(n--){
        cin >> left >> top >> right;
        maxright = max(maxright, right);
        for(int i=left;i<right;i++){
            arr[i] = max(arr[i],top);
        }
    }

    for(int i=1;i<maxright;i++){
        if(arr[i]!=arr[i-1]){
            cout << i << " " <<arr[i] << " ";
        }
    }
    cout << maxright << " " << 0;
    return 0;
}
