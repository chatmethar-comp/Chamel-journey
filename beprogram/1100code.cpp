#include<bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0);
    long long a[3][10], b[3][100], c[1000];
    // 3 in a & b mean ith digit;
    // 10 in a mean number of 0-9 that occurred in i th(0,1,2);
    // 100 mean number of 0-11 that occurred in i th digit
    // is number that input occured
    for(int i=0;i<3;i++){
        for(int j=0;j<10;j++){
            a[i][j]=0;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<100;j++){
            b[i][j]=0;
        }
    }
    for(int j=0;j<1000;j++){
        c[j]=0;
    }

    long long ans=0;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        long long f;
        cin >> f;
        long long j = f/100;           // first digit
        long long k = (f/10)%10;       // second digit
        long long l = f%10;            // last digit

        ans += a[0][j] + a[1][k] + a[2][l];

        long long x = j*10+k;        // first-second
        long long y = k*10+l;        // second-last
        long long z = l*10+j;        // last-first

        ans -= b[0][x] + b[1][y] + b[2][z];
        ans += c[f];
        // n(a u b u c) = n(a) + n(b) + n(c) - n(a ^ b) - n(b ^ c) - n(c ^ a) + n(a ^ b ^ c)
        a[0][j]++;a[1][k]++;a[2][l]++;
        b[0][x]++;b[1][y]++;b[2][z]++;
        c[f]++;
    }
    cout << ans;
    return 0;
}
