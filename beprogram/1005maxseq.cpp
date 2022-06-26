#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int maxi=0;
    int sum=0;
    int start, stop;
    for(int i=0;i<n;i++){
        sum=arr[i];
        for(int j=i+1;j<n;j++){
            sum+=arr[j];
            if(maxi<sum){
                maxi=sum;
                start=i;
                stop=j;
            }
            if(sum<0){
                break;
            }
        }
    }
    if(!maxi){
        cout << "Empty sequence";
        return 0;
    }
    for(int i=start;i<=stop;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << maxi;

    return 0;
}
