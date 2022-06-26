#include<bits/stdc++.h>
using namespace std;

struct date
{
    int day;
    int month;
    int year;
};

struct employee
{
    char name[40];
    char addres[40];
    long zipcode;
    double salary;
    struct date birthdate;
    struct date hiredate;
};

int main()
{
    struct employee emp1 = {"Somjit Sukjai",
                            "chareonkun 1 ladkrabaan",
                            66789,
                            15000,
                            {20,12,1500},
                            {22,10,2021}
                           };
    cout << emp1.name << endl << emp1.addres << endl << emp1.zipcode << endl << emp1.salary << endl << emp1.birthdate.day << " " << emp1.birthdate.month << " " << emp1.birthdate.year << endl << emp1.hiredate.day << " " << emp1.hiredate.month << " " << emp1.hiredate.year;
    return 0;
}


