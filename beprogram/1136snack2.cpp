#include<bits/stdc++.h>
using namespace std;
int a_size, b_size, ta, tb, ans=0;
double k, a_mean=0, b_mean=0;
vector<double> a, b;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> a_size >> b_size;
    for(int i=0;i<a_size;i++){
        cin >> k;
        a_mean+=k;
        a.push_back(k);
    }
    for(int i=0;i<b_size;i++){
        cin >> k;
        b_mean+=k;
        b.push_back(k);
    }
    a_mean/=a_size;b_mean/=b_size;
    if(a_mean>b_mean){
        swap(b_mean,a_mean);
        swap(b_size,a_size);
        swap(a,b);
    }
    ta=a_size, tb=b_size;
    for(int i=0;i<b_size;i++){
        if(b[i]<b_mean&&b[i]>a_mean&&tb>1){
            a_mean=(a_mean*ta+b[i])/(ta+1);
            b_mean=(b_mean*tb-b[i])/(tb-1);
            ans++;
            ta++;tb--;
        }
    }
    cout << ans;
    return 0;
}
