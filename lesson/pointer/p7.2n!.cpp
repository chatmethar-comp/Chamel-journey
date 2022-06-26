#include<bits/stdc++.h>
using namespace std;

void swap(char *a, char *b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(char *arr, int start, int end){
    int i;
    if(start==end){
        for(i=0;i<=end;i++){
            if(*(arr+i)=='r'){
                cout << "red ";
            }
            if(*(arr+i)=='g'){
                cout << "green ";
            }
            if(*(arr+i)=='b'){
                cout << "blue ";
            }
        }
        cout << endl;
    } else {
        for(i=start;i<=end;i++){
            swap(arr+start, arr+i);
            permutation(arr, start+1,end);
            swap(arr+start, arr+i);
        }
    }
}

int main()
{
    char rgb[] = "rgb";
    permutation(rgb, 0, 2);
}
