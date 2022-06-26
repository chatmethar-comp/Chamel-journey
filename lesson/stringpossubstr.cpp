#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str = "We think in generalities, but we live in details.";
    string str2 = str.substr(3,5);
    size_t pos = str.find("live");
    string str3 = str.substr(3);
    cout << str2 << endl << str3 ;
    return 0;
}
