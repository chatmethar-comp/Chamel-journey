#include<bits/stdc++.h>
using namespace std;
void strcopy(char *str1, char *str2){
    while(*str1 !='\0'){
        *str2 = *str1;
        str1++;
        str2++;
    }
}
int main()
{
    char str1[] = "abscd";
    char str2[10];
    strcopy(str1,str2);
    cout << str1 << endl << str2  ;
}
