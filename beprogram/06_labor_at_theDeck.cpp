#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long  n, work;
    scanf("%d %d", &n, &work);
    long long labor[n];
    for(long long  i=0;i<n;i++){
        scanf("%lld", &labor[i]);
    }
    long long left=0, right=1e18;

    long long done=0;
    long long mid;
    while(left<right){
        mid = (left+right)/2;
        done=0;
        for(long long i=0;i<n;i++){
            done+= mid/labor[i];
            if(done>=work){
                break;
            }
        }
        if(done>=work){
            right=mid;
        } else {
            left=mid+1;
        }
    }
    printf("%lld",left);
    return 0;
}
// out 181920isincorrect.
