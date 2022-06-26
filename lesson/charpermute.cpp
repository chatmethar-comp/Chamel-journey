#include<bits/stdc++.h>
using namespace std;

void charpermute(char str[], int left, int right)
{
    if(left==right){
        cout << str<< endl;
    } else {
        for(int i=left;i<=right;i++){
            swap(str[left],str[i]);
            cout << "process: " << str  << "left " << left << " " << i <<endl;
            charpermute(str, left+1, right);
            swap(str[left],str[i]);
        }
    }
}

int main()
{
    char str[] = "abcd";
    charpermute(str, 0, 3);
    cout << str;
    return 0;
}
