#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=5;
    arr[] = {2,3,4,5,1};
    vector<int> smal;
    smal=SmallestonLeft(arr, n);
    for(auto i:smal){
        cout << smal << " ";
    }
}

vector<int> SmallestonLeft(int arr[], int n)
{
    set<int> s;
    s.clear();
    auto it = s.begin();
    int min=INT_MAX;
    int k=0, index=-1;
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            min = arr[i];
            index = i;
        }
        auto itr = s.insert(arr[i]);
        it = itr.first;
        auto f = s.begin();
        if(it !=s.end() && *f < arri)
    }
}
