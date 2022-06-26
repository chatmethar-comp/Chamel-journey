#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[] = {12,4,56,85,27,14,8,45,10,9};
    int sumEven = 0;
    for(int i=0;i<10;i++){
        if(*(a+i)%2==0){
            sumEven+=*(a+i);
        }
    }
    cout << sumEven;
}
