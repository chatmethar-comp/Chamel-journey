// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
       // Your code here
       int N_subset = (1<<n)-1;
       int sum;
       int count=0;
       int count_value;
       int max_val=0;
       for(int i=1;i<=N_subset;i++){
           sum=0;
           count_value=0;
           for(int j=i, k=1;k<=n;j=(j>>1),k++){
               if(j%2){
                   sum+=wt[k-1];
                   count_value+=val[k-1];
               }
               if(sum>W){
                   break;
               }
           }
           if(sum<=W){
               count++;
               max_val=max(max_val,count_value);
           }
       }
       return max_val;
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;

        int val[n];
        int wt[n];

        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];

        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;

    }
	return 0;
}  // } Driver Code Ends
