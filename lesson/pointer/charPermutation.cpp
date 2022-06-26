#include<bits/stdc++.h>
using namespace std;

void swap(char*ch1, char*ch2){
    char temp;
    temp = *ch1;
    *ch1 = *ch2;
    *ch2 = temp;
}

void charPermu(char *ch, int start, int end){
    int i;
    if(start==end){
        cout << ch << endl;

    } else {
        for(i=start;i<=end;i++){
            swap(ch+start, ch+i);
            charPermu(ch,start+1,end);
            swap(ch+start, ch+i);
        }
    }
}
int main()
{
    char a[] = "abcd";
    charPermu(a,0,sizeof(a)/sizeof(char)-2);
    return 0;
}
