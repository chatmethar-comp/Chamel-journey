#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    float cake[] = {1,0.75,0.5,0.25,0.125};
    double temp, sum=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            cin >> temp;
            sum += temp*cake[j];
        }
    }
    cout << ceil(sum);
    return 0;
}
// cheat f0x
