#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
int main()
{
    char sentence[10];
    char *Ptr;
    int count;
    Ptr=sentence;
    for(count=0;count<10;count++){
        *Ptr = getchar();
        Ptr++;
    }
    for(count=0;count<10;count++){
        Ptr--;
        putchar(*Ptr);
    }
    return 0;
}
