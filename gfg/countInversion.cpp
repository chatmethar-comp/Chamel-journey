// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:

long long merge(long long arr[], long long left, long long middle, long long right){
    long long arrSize_1 = middle-left+1;
    long long arrSize_2 = right-middle;
    long long* subarr_1 = new long long[arrSize_1];
    long long* subarr_2 = new long long[arrSize_2];

    long long count=0;
    long i;
    for(i=0;i<arrSize_1;i++){
        subarr_1[i] = arr[left+i];
    }
    for(i=0;i<arrSize_2;i++){
        subarr_2[i] = arr[middle+1+i];
    }

    long long i_1=0, i_2=0;
    i=left;
    while(i_1<arrSize_1 && i_2<arrSize_2){
        if(subarr_1[i_1] <= subarr_2[i_2]){
            arr[i] = subarr_1[i_1];
            i++;i_1++;
            count++;
        } else {
            arr[i] = subarr_2[i_2];
            i++;i_2++;
        }
    }

    while(i_1<arrSize_1){
        arr[i] = subarr_1[i_1];
        i++;i_1++;
    }
    while(i_2<arrSize_2){
        arr[i] = subarr_2[i_2];
        i++;i_2++;
    }
}

long long mergeSort(long long arr[], long long left, long long right){
    long long middle = (left+right)/2;
    long long count=0;
    if(right>left){
       mergeSort(arr,left,middle);
        mergeSort(arr,middle+1,right);
        count += merge(arr,left,middle,right);
    }
    return count;
}

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    return mergeSort(arr,0,N);
}

};

// { Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while(T--){
        long long N;
        cin >> N;

        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }

    return 0;
}
  // } Driver Code Ends
