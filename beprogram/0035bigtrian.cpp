#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x[n], y[n];
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i];
    }
    float area=0, big_area=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                area=abs(x[i]*y[j] + x[j]*y[k] + x[k]*y[i] - y[i]*x[j] - y[j]*x[k] -y[k]*x[i])/2.0;
                if(big_area<area){
                    big_area = area;
                }
            }
        }
    }
    printf("%.3f",big_area);
    return 0;
}
