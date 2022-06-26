#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
        int MissingNumber(vector<int>& array, int n){
            int sum=0;
            for(int i=0;i<n-1;i++){
                sum+=array[i];
            }
            return (((n*(n+1))/2) - sum);
        }
};

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n-1);
        for(int i=0;i<n-1;i++){
            cin >> arr[i];
        }
        solution sol;
        cout << sol.MissingNumber(arr, n);
    }

}
