#include<bits/stdc++.h>
using namespace std;

void subArraySum(int A[], int N, int S)
{
    int start=1, endding=0;
    int subsum = 0;
    for(int i=0;i<N;i++){
        //cout << start << " " << endding << endl;
        subsum+=A[i];
        //cout << subsum << endl;
        while(subsum>S){
            subsum-=A[start-1];
            //cout << subsum << endl;
            start++;
        }
        endding++;
        if(subsum==S){
            cout << start << " " << endding << endl;
            return;
        }
        if(start==endding){
            endding
        }
    }
}

int main()
{
    int N = 5;
    int S = 12;
    int A[] = {1,2,3,7,5};
    subArraySum(A, N, S);
    return 0;
}
