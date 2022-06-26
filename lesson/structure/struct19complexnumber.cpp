#include<bits/stdc++.h>
using namespace std;

struct complex_num
{
    float re_part;
    float im_part;
};

struct complex_num add(struct complex_num a, struct complex_num b)
{
    struct complex_num c;
    c.im_part = a.im_part + b.im_part;
    c.re_part = a.re_part + b.re_part;
    return c;
};

int main()
{
    struct complex_num cp1, cp2, cp3;
    cp1.im_part = 1;
    cp1.re_part = 3;
    cp2.im_part = 5.4;
    cp2.re_part = 1.2;
    cp3 = add(cp1, cp2);
    cout << cp3.im_part << " " << cp3.re_part;
    return 0;
}
