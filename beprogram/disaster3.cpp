#include<bits/stdc++.h>
using namespace std;
int n, c=0, st, en;
string p;
int a[26];
int main()
{
    memset(a, 0, sizeof(a));
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> p;
        a[p[0]-'A']++;a[p[1]-'A']++;
    }
    for(int i=0;i<26;i++)
    {
        if(a[i]==1&&!c){
            c++;
            st=i;
        } else if(a[i]==1&&c){
            en=i;
        }
    }
    cout << st << " " << en;
}
