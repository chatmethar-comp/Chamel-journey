#include<bits/stdc++.h>
using namespace std;

int longSubarrSumDivK(int arr[], int n, int k)
{
    unordered_map<int,int> um;
    int mx=0;
    int curr_sum=0;
    for(int i=0;i<n;i++){

        curr_sum+=arr[i];
        int mod=((curr_sum))%k;
        if(mod==0)
            mx=i+1;
        else if(um.find(mod)==um.end())
            um[mod]=i;
        else
            if(mx<(i-um[mod]))
                mx=i-um[mod];
        cout << curr_sum << " " << mx << " " << mod << endl;
    }
    return mx;
}

int main()
{
    int arr[]={2,7,6,1,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    cout << longSubarrSumDivK(arr,n,k);
    return 0;
}
