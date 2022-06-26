#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxProduct(vector<int> arr, int n)
    {
        long long minVal = arr[0];
        long long maxVal = arr[0];
        long long maxProduct = arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]<0){
                cout << "swap" << endl;
                swap(maxVal, minVal);
            }
            cout << maxVal << " " << minVal << " " << maxProduct << endl;
            maxVal = max((long long)arr[i], maxVal*arr[i]);
            minVal = min((long long)arr[i], minVal*arr[i]);
            cout << maxVal << " " << minVal << " " << maxProduct << endl;
            maxProduct = max(maxProduct, maxVal);
        }
        return maxProduct;
    }
};

int main()
{
    int n, i;
    cin >> n;
    vector<int> arr(n);
    for(i=0;i<n;i++){
        cin >> arr[i];
    }
    Solution ob;
    auto ans = ob.maxProduct(arr, n);
    cout << ans << endl;
    return 0;
}
