#include<bits/stdc++.h>
using namespace std;

void display(int a[], int n)
{
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void findPermutations(int a[], int n)
{
//    sort(a, a+n);
    do{
        display(a,n);
    } while (next_permutation(a, a+n));
}

int main()
{
    char a[] = "kan";
    int n = 5;
    findPermutations(a, n);
    display(a,n);
    return 0;
}
