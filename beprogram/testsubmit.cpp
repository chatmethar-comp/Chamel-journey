#include<bits/stdc++.h>
using namespace std;

void D_command(int qarray[], int n)
{
    int d=qarray[0];
    for(int i=0;i<n-1;i++){
        qarray[i]=qarray[i+1];
    }
    qarray[n-1]=0;
}

void Insert(int array[],int index, int value,int n)
{
    for(int i=n-1;i>index;i++){
        array[i] = array[i-1];
    }
    array[index] = value;
    return;
}

int main()
{
    int a[]= {1,2,3,4,5};
    Insert(a,2,7,5);
    for(int i=0;i<5;i++){
        cout << a[i] << " ";
    }
}
