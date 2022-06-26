#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    void  swap(int* a, int* b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void sort012(int a[], int n){
        // elements before low is 0
        // elements after high is 2
        // using mid to iterate low to high
        // mean we need to make element between low and high is 1
        int low=0,mid=0,high=n-1;
        while(mid <= high){
            if(a[mid]==0){
                swap(&a[mid],&a[low]);
                mid++;
                low++;
            }
            // if that iterating element is 0, swap it with low element;
            else if(a[mid]==1){
                mid++;
            }
            // if that iterating element is 1, pass it.
            else {
                swap(&a[mid], &a[high]);
                high--;
            }
            // iterating element is 2; swap it with high element;
            cout << mid << " " ;
            for(int i=0;i<n;i++){
                cout << a[i] << " ";
            }
            cout << endl;
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
        ob.sort012(a,n);
        for(int i=0;i<n;i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
