#include<bits/stdc++.h>
using namespace std;
int arr[] = {4,5,8,9,8,1,0,1,9,3};
int *array_ptr;
int main()
{
    array_ptr = arr;
    while(*array_ptr!=0){
        cout << *(array_ptr++) << " ";
    }
    return 0;
}
