#include<bits/stdc++.h>
using namespace std;

long sumArray(int *arr, int n);

int main()
{
    int Y[5]={5,7,9,11,13};
    long s;
    s=sumArray(Y,5);
    cout << s;
    for(int i=0;i<5;i++){
        cout << *(Y+i) << endl;
    }
}

long sumArray(int *arr, int n){
    long sum=0;
    for(int i=0;i<n;i++){
        sum+=*arr;
        arr++;
    }
    return sum;
}
