#include<bits/stdc++.h>
using namespace std;

typedef struct
{
    string name;
    int accNo;
    float newBalance;
} bookAcc;

bookAcc *readData()
{
    bookAcc tempAcc;
    bookAcc *AccPtr;
    cout << "Read book account from customer" << endl;
    cout << "name : ";
    cin >> tempAcc.name;
    cout << "Accout Number : ";
    cin >> tempAcc.accNo;
    cout << "Current Balance : ";
    cin >> tempAcc.newBalance;
    AccPtr = (bookAcc *)malloc(sizeof(bookAcc));
    AccPtr = &tempAcc;
    return AccPtr;
}

void printData(bookAcc *AccPtr)
{
    cout << "=====Print Data=====" << endl;
    cout << "name : " << AccPtr->name << endl;
    cout << "Account Number : " << AccPtr->accNo << endl;
    cout << "Current Balance : " << AccPtr->newBalance << endl;
}

int main()
{
    bookAcc *customer;
    cout << "This program process book account for customer" << endl;
    customer = readData();
//    cout << customer->name << " " << *(customer).accNo << " " <<customer.newBalance;
    printData(customer);
    return 0;
}
