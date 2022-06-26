#include<bits/stdc++.h>
using namespace std;
#include<math.h>

int main()
{
    int n;
    cin >> n;
    int S[11], B[11];
    for(int i=1;i<=n;i++){
        cin >> S[i] >> B[i];
    }
    //S[0] = ???!?!OIJf9
    int pos=pow(2,n)-1;
    //possibilities of choosing ingredients is 2^n
    // -1 means the way that not choose all ingredient;
    int delicious=INT_MAX;
    for(int i=1;i<=pos;i++)
    {
        int s=1;
        int b=0;
        for(int j=1,bit=i;j<=i;j++,bit=bit>>1) //step bit by right ship to get next bit
        {
            //if that bit ending with 1 mean we choose that ingredient
            if(bit%2==1){
                s*=S[j];
                b+=B[j];
            }
        }
        delicious = min(delicious,abs(s-b));
    }
    cout << delicious;
}
