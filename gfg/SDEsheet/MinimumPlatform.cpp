#include<bits/stdc++.h>
using namespace std;
const int mxN=5e4;
int n;
int arr[mxN], dep[mxN];

int findPlatform()
{
    int c=0;
    sort(arr,arr+n);
    sort(dep,dep+n);
    int i=0, j=0, m=0;
    while(i<n&&j<n){
        if(arr[i]<=dep[j]){
            c++;
            i++;
        }
        else {
            c--;
            j++;
        }
        m=max(m,c);
    }
    return m;
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    for(int i=0;i<n;i++)
        cin >> dep[i];
    cout << findPlatform();
    return 0;
}
