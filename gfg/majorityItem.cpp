#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findCandidate(int a[], int size){
        int maj_index=0, count=1;
        for(int i=1;i<size;i++){
            if(a[maj_index]==a[i]){
                count++;
            }
            else {
                count--;
            }
            if(count==0){
                maj_index=i;
                count=1;
            }
            cout << maj_index << endl;
        }
        return a[maj_index];
    }

    bool isMajority(int a[], int size, int cand){
        int count=0;
        for(int i=0;i<size;i++){
            if(a[i]==cand){
                count++;
            }
        }
        if(count>size/2){
            return 1;
        } else {
            return 0;
        }
    }

    int majorityItem(int arr[], int size){
        if(isMajority(arr, size, findCandidate(arr, size)))
        {
            return findCandidate(arr, size);
        } else {
            return -1;
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        Solution ob;
        cout << ob.majorityItem(a,n) << endl;
    }
}
