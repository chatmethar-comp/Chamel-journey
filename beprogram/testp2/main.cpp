#include <iostream>

using namespace std;
#define mxN 100
int main()
{
    cout << "Hello world!" << endl;
    int n, a[mxN];
    cin >> n;

    for(int i=0;i<n;i++)
        cin >> a[i];
    int max_el=0,ind=-1;
    for(int i=0;i<n;i++){
        if(a[i]>max_el||ind==-1){
            max_el=a[i];
            ind=i;
        }
    }
    cout << max_el <<  " " << ind;
    return 0;
}
