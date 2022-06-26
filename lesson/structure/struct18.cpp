#include<bits/stdc++.h>
using namespace std;

struct example
{
    float f;
    int i;
    char c;
};

struct example assign_value(float f, int i, char c)
{
    struct example a;
    a.f = f;
    a.i = i;
    a.c = c;
    return a;
};

int main()
{
    float data1 = 1.2;
    int data2 = 3;
    char data3 = 'k';
    struct example a;
    a = assign_value(data1, data2, data3);
    cout << a.f << " " << a.i << " " << a.c;
    return 0;
}
