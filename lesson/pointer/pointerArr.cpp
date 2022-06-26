#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[5] = {2,9,5,4,8};
    int* ptr1;
    ptr1 = a;
    int *ptr2 = &a[0];
    ptr2 = ptr2+1;
//    cout << a[0] << endl;
//    cout << *ptr1 << endl;
//    cout << *(ptr2) << endl;
//    cout << *a;
    // *ptr1 == *a == a[0]
    // *(ptr+1) == a[1]
//    for(int i=0;i<5;i++){
//        cout << *(a+i) << endl;
//    }
    int *ptr3, *ptr4;
    ptr3=a;
    ptr4=a;
    *ptr3 = 3;
    *ptr4 = 4;
    ptr3++;
    *ptr3 = 5;
    ptr3++;
    *ptr3 = 6;
    ptr4+=2;
    *ptr4=10;
    *(a+4)=15;
    for(int i=0;i<5;i++){
        cout << *(a+i) << " ";
    }
}
