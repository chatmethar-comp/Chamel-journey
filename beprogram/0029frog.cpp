#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x, y;
    cin >> x >> y;
    if(y>=x)
        cout << ceil(y/(float)x);
    else
        cout << 2;
    return 0;
}
