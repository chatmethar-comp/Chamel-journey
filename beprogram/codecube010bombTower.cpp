#include<bits/stdc++.h>
using namespace std;
vector<long long> p;
bool ch;
int main()
{
    long long n, b, c=0;
    cin >> n >> b;
    for(int i=2;i<=n;i++){
        ch=1;
        for(auto a : p){
            if(a*a>i){
                break;
            }
            if(i%a==0){
                ch=0;
                break;
            }
        }
        if(ch){
            c++;
            p.push_back(i);
        }
    }
    cout << max((long long)(0),c-b);
    return 0;
}
