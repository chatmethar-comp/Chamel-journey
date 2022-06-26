#include<bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n, k;
    char opr;
    cin >> n;
    while(n--){
        cin >> opr;
        if(opr=='P'){
            cin >> k;
            pq.push(k);
        }
        else{
            if(pq.empty())
                cout << "-1\n";
            else {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
    }
    return 0;
}
