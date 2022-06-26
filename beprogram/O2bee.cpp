#include<bits/stdc++.h>
using namespace std;
const int mxN=25;
int s[mxN], w[mxN];
int a;
vector<int> y;
int main()
{
    w[0]=1;
    s[0]=0;
    for(int i=1;i<25;i++){
        s[i]=w[i-1];
        w[i]=s[i-1]+w[i-1]+1;
    }

    while(1){
        cin >> a;
        if(a==-1)
            exit(0);
        cout << w[a] << " " << s[a]+w[a]+1 << endl;
    };

    return 0;
}
/*
queen   -> q, w
work    -> s, w
soldier -> w
*/
