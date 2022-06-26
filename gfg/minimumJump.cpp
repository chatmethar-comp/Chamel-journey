// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:

    int findmaxindex(int arr[], int n){
        int maxIndex = -1;
        for(int i=0;i<n;i++){
            if(maxIndex<arr[i]){
                maxIndex = i;
            }
        }
        return maxIndex;
    }

    int minJumps(int arr[], int n){
        // Your code here
        int count = 0;
        int current = 1;
        while(current<n){
            int select[arr[current-1]];
            for(int i=current-1;i<arr[current-1]+1;i++){
                select[i-current+1] = arr[i];
            }
            current += findmaxindex(select, arr[current]-1) + 1;
            count++;
        }
        return count;
    }

    int maxrange

    int minJump2(int arr[], int n){
        if(n<1){
            return 0;
        }
        if(arr[0]==0){
            return -1;
        }
        int maxrange=steps=arr[0];
        int jumps=1;
        for(int i=1;i<n;i++){
            if(i==arr.length-1)
            {
                return jumps;
            }
            maxrange=max(maxrange,i+arr[i]);
            steps--;
            if(step==0){
                jumps++;
                if(i>=maxrange){
                    return -1;
                }
                step = maxrange-i;
            }
        }
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
