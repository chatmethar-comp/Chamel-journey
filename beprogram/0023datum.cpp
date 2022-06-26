#include<bits/stdc++.h>
using namespace std;
int main()
{
    int days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int d, m;
    cin >> d >> m;
    int days;
    days=d;
    for(int i=0;i<m-1;i++){
        days+=days_in_month[i];
    }
    switch(days%7)
    {
    case 0:
        cout << "Wednesday";
        return 0;
    case 1:
        cout << "Thursday";
        return 0;
    case 2:
        cout << "Friday";
        return 0;
    case 3:
        cout << "Saturday";
        return 0;
    case 4:
        cout << "Sunday";
        return 0;
    case 5:
        cout << "Monday";
        return 0;
    case 6:
        cout << "Tuesday";
    }
    return 0;
}

/*
1 1 thu

sun mon tue wed thu fri sat
                 1   2   3
 4   5   6   7   8   9   10
 11  12  13  14  15  16  17
*/
