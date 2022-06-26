#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=7;
    int m=20;
    cout << n << " " << &n << endl;
    cout << m << " " << &m << endl;
    int* p1; // p1 is a pointer to int
    char* c1; // pointer to char
    p1 = &m;
    cout << "p1 = &m" << endl;
    cout << "p1 = " << p1 << endl;
    cout << "*p1 = " << *p1 << endl;
    // *p1 is deferencing, detect data in location;
    m = 99;
    cout << "---- m = 99 ----" <<endl;
    cout << "pi = " << *p1 << endl;
    cout << "---------------------------" << endl;
    int price = 20;
    int *coke, *pepsi, *fanta;
    coke = &price;
    pepsi = &price;
    fanta = &price;
    cout << "*coke = " << *coke << " *pepsi = " << *pepsi << " *fanta = " << *fanta <<endl;
    price = 10;
    *fanta = 19;
    cout << "*fanta=19;" << endl;
    cout << "*coke = " << *coke << " *pepsi = " << *pepsi << " *fanta = " << *fanta <<endl;
    int* ptr2;
    int a = 19;
    ptr2=&a;
    *ptr2=100;
    cout << a;
}
