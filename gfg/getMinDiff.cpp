#include<bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k) {
    if(n==1){
        return 0;
    }
    sort(arr,arr+n);
    int diff = arr[n-1] - arr[0];
    int mini,maxi;
    for(int i=1;i<n;i++){
        if(arr[i]-k < 0){
            continue;
        }
        maxi = max(arr[i-1]+k, arr[n-1]-k);
        mini = min(arr[0]+k, arr[i]-k);
        diff = min(diff,maxi-mini);
    }
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return diff;
}

// not work
int mygetMinDiff(int arr[], int n, int k) {
    for(int i=0;i<n;i++){
        if(arr[i]<=k){
            arr[i]+=k;
        } else {
            arr[i]-=k;
        }
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return arr[n-1]-arr[0];
}

int getMinDiffSol(int arr[], int n, int k)
{
    vector<pair<int,int>> v;
    vector<int> taken(n);

    for(int i=0;i<n;i++){
        if(arr[i]-k>=0){
            v.push_back({arr[i]-k, i});
        }
        v.push_back({arr[i]+k,i});
    }
    sort(v.begin(),v.end());
    int elements_in_range = 0;
    int left = 0;
    int right = 0;
    while(elements_in_range<n && right < v.size()){
        elements_in_range++;
        taken[v[right].second]++;
        right++;
        cout << elements_in_range << " " << left << " " << right << endl;
    }
    int ans = v[right-1].first - v[left].first;
//    cout << v[right-1].first << " " << v[left].first << " " << ans << endl;
    for(int i: taken){
        cout << i << endl;
    }
    while(right<v.size()){
        cout << taken[v[left].second]<< endl;
        if(taken[v[left].second] == 1){
            elements_in_range--;
        }
        taken[v[left].second]--;
        left++;


        while(elements_in_range < n && right < v.size()){
            if(taken[v[right].second] == 0){
                elements_in_range++;
            }
            taken[v[right].second]++;
            right++;
        }
        if(elements_in_range==n){
            ans = min(ans, v[right-1].first - v[left].first);
        } else {
            break;
        }
    }
//    for(auto i: v){
//        cout << i.first << " " << i.second << endl;
//    }
    return ans;
}

int main()
{
    int n=10, k=5;
    int arr[] = {2,6,3,4,7,2,10,3,2,1};
    //cout << getMinDiff(arr,n,k) << endl << mygetMinDiff(arr,n,k) << endl;
    cout << getMinDiffSol(arr,n,k);
    return 0;
}
