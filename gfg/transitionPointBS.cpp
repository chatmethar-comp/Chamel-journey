#include<bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
}

int transitionPoint(int arr[], int n){
    if(arr[0]){
        return 0;
    }
    int lb=0, ub=n-1;
    while(lb<=ub){
        int mid = (lb+ub)/2;

        if(arr[mid]==0)
            lb=mid+1;
        else if(arr[mid]==1){
            if(arr[mid-1]==0){
                return mid;
            }
            ub=mid-1;
        }
    }
    return -1;
}






