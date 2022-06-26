#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
int n, k, p;
deque<ar<int,2>> dq;

//void printq()
//{
//    for(ar<int,2> i : dq){
//        cout << i[0] << " " << i[1] << " ,  ";
//    }
//    cout << "\n\n";
//}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    cin >> p; dq.push_back({p,1});
    for(int i=2;i<=n;i++){
        cin >> p;
        while(dq.size()&&i-dq.front()[1]>k)
            dq.pop_front();
        while(dq.size()&&dq.back()[0]>dq.front()[0]+p)
            dq.pop_back();
        dq.push_back({dq.front()[0]+p,i});
//        printq();
    }
    cout << dq.front()[0]+p;
    return 0;
}
