#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long ans=1;
    for(int i=0;i<n;i++){
        ans*=2;
        ans=ans%((int)1e9+7);
    }
    cout << ans;
    return 0;
}
