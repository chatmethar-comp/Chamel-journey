#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int cols = (n%2)? n : n-1;

    for(int row=1;row<=ceil(n/2.0);row++){
        for(int col=ceil(cols/2.0)-row;col>=1;col--){
            cout << "-";
        }
        cout << "*";
        for(int mid=2*(row-1)-1;mid>=1;mid--){
            cout << "-";
        }
        if(row!=1 ){
            cout << "*";
        }
        for(int col=ceil(cols/2.0)-row;col>=1;col--){
            cout << "-";
        }
        cout << endl;
    }
    int row=1;
    if(n%2==0){
        row=row-1;
        n=n-1;
    }
    for(row;row<=n/2;row++){

        for(int space=1;space<=row;space++){
            cout << "-";
        }
        cout << "*";
        for(int mid=2*(n/2-row)-1;mid>=1;mid--){
            cout << "-";
        }
        if(row!=n/2){
            cout << "*";
        }
        for(int space=1;space<=row;space++){
            cout << "-";
        }
        cout << endl;
    }
}
