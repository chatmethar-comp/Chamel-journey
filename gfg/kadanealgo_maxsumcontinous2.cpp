#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    long long maxSubarraySum(int arr[], int n){
        long sum=0, maxsub=arr[0];
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>maxsub){
                maxsub = sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return maxsub;
    }
};

int main()
{
    // t == testcase
    // n == size of array
    // a == array
    int n, t;
    cin >> t;
    while(t--){
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        solution ob;
        cout << ob.maxSubarraySum(a, n) << endl;
    }
    return 0;
}
