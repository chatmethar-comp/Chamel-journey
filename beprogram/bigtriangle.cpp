#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x[n], y[n];
    float sum=0;
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i];
    }
    for(int i=0;i<n;i++){
        if(i==n-1){
            sum+= (x[i]*y[0]);
        } else {
            sum+= (x[i]*y[i+1]);
        }


    }
    cout << sum << endl;
    for(int i=0;i<n;i++){
        if(i==n-1){
            sum-= (y[i]*x[0]);
        } else {
            sum-= (y[i]*x[i+1]);
        }
    }
    cout << sum << endl;
    sum=sum/2.0;
    cout << abs(sum);
    return 0;
}
