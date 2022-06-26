#include<bits/stdc++.h>
using namespace std;
vector<int> SmallestonLeft(int arr[], int n);

int main()
{
    int n=5;
    int arr[] = {2,3,4,5,1};
    vector<int> b;
    b = SmallestonLeft(arr, n);
    for(int i: b){
        cout << i << " ";
    }
}
vector<int> SmallestonLeft(int arr[], int n){
    vector<int> result;
    set<int> s;
    for(int i=0;i<n;i++){
        auto itr=s.lower_bound(arr[i]);
        if(itr==s.begin()){
            result.push_back(-1);
        } else {
            itr--;
            result.push_back(*itr);
        }
        s.insert(arr[i]);
    }
    return result;
}
