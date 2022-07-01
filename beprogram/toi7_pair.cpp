#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=1e5;
int n;
ar<int,2> a[mxN], tmp[mxN];
ll ans=0;
// mergesort
void ms(int l,int r)
{
    int mid=(l+r)>>1, t=0;
    ll cnt=0, sum=0;
    if(l>=r)
        return;
    ms(l,mid);
    ms(mid+1,r);
    int i=l,j=mid+1;
    while(1){
        if(a[i][1]>a[j][1]){
            tmp[t++]=a[j];
            cnt++;
            sum+=a[j][0];
            j++;
        } else {
            ans+=(a[i][0]*cnt+sum);
            tmp[t++]=a[i];
            i++;
        }
        if(i==mid+1){
            for(int k=j;k<=r;k++)
                tmp[t++]=a[k];
            break;
        }
        if(j==r+1){
            for(int k=i;k<=mid;k++){
                ans+=(cnt*a[k][0]+sum);
                tmp[t++]=a[k];
            }
            break;
        }
    }
    for(int i=0;i<t;i++)
        a[l+i]=tmp[i];
    return;
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i][0] >> a[i][1];
    }
    sort(a,a+n);
    ms(0,n-1);
    cout << ans;
    return 0;
}
