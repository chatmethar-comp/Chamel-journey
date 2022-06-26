#include<bits/stdc++.h>
using namespace std;

void display(char a[], int n){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void findPermutation(char a[], int n){
    cout << "Possible permutations are: \n";
    do{
        display(a,n);
    } while(next_permutation(a,a+n));
}

int main()
{
    char a[] = "abc";
//    int n = sizeof(a)/sizeof(a[0]);
    findPermutation(a,3);
    return 0;
}
