#include<bits/stdc++.h>
using namespace std;
int n, q, a[20010];
int A, B, S, E, cnt;
int main()
{
    cin >> n >> q;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<q;i++){
        cin >> A >> B >> S >> E;
        cnt=0;
        for(int j=A-1;j<=B-1;j++){
            if(a[j]>=S&&a[j]<=E)
                cnt++;
        }
        cout << cnt << " ";
    }
    return 0;
}
