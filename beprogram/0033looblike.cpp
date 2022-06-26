#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int com[n];
    int freq[n];
    for(int i=0;i<n;i++){
        cin >> com[i];
        freq[i]=0;
    }
    sort(com, com+n);
    int count=0;
    int max_index=0;
    for(int i=0;i<n;i++){
        if(com[i]==com[i+1]){
            count++;
        } else {
            if(freq[max_index]<count){
                max_index=i;
            }
            freq[i]=count;
            count=0;
        }
    }
    for(int i=0;i<n;i++){
        if(freq[i]==freq[max_index]){
            cout << com[i] << " ";
        }
    }
    return 0;
}
