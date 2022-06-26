//Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number)
//which has the maximum sum and return its sum.
//Example 1:
//
//Input:
//N = 5
//Arr[] = {1,2,3,-2,5}
//Output:
//9
//Explanation:
//Max subarray sum is 9
//of elements (1, 2, 3, -2, 5) which
//is a contiguous subarray.
//Example 2:
//
//Input:
//N = 4
//Arr[] = {-1,-2,-3,-4}
//Output:
//-1
//Explanation:
//Max subarray sum is -1
//of element (-1)

#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n)
{
    int sum=0, maxsub=arr[0];
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>maxsub){
            maxsub=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return maxsub;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    //int arr[] = {1, 2, 3, -2, 5};
    //int n = 5
    cout << maxSubarraySum(arr, n);
}











