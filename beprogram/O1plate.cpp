#include<bits/stdc++.h>
using namespace std;
int m, n, stu, c, st;
char cmd;
unordered_map<int,int> stus;
queue<int> qu[12];
deque<int> ord;
int main()
{
    cin >> m >> n;
    for(int i=0;i<n;i++){
        cin >> c >> st;
        stus.insert({st,c});
    }
    while(1){
        cin >> cmd;
        if(cmd=='E'){
            cin >> stu;
            qu[stus[stu]].push(stu);
            if(find(ord.begin(),ord.end(),stus[stu])==ord.end())
                ord.push_back(stus[stu]);
        }
        else if(cmd=='D'){
            cout << qu[ord.front()].front() << endl;
            qu[ord.front()].pop();
            if((qu[ord.front()]).empty())
                ord.pop_front();
        }
        else
            break;
    }
    cout << "0";
    return 0;
}
