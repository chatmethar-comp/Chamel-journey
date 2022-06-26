#include<bits/stdc++.h>
using namespace std;
int main()
{
    struct date
    {
        int day;
        char mon_name[4];
        int year;
    };
    struct date d;
    d.day = 4;
    d.year = 2004;
    d.mon_name[0] = 'A';
    d.mon_name[1] = 'P';
    d.mon_name[2] = 'R';
    cout << d.day << " " << d.mon_name << " " << d.year;
    //if(strcmp(d.mon_name,"AUG")==0)
}
