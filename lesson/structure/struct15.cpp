#include<bits/stdc++.h>
using namespace std;
struct student
{
    string name;
    string id;
    char grade;
};
int main()
{
    struct student classroom[5];
    int count=0;
    for(int i=0;i<5;i++){
        cin >> classroom[i].name >> classroom[i].id >> classroom[i].grade;
        if(classroom[i].grade=='A'){
            count++;
        }
    }
    cout << count << " students get grade A";
    return 0;
}
