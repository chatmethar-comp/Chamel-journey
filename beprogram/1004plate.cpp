#include<bits/stdc++.h>
using namespace std;

int find_class(int ID,int classes[],int student[], int n)
{
    for(int i=0;i<n;i++){
        if(ID==student[i]){
            return classes[i];
        }
    }
    return 0;
}

void Insert(int array[],int index, int value,int n)
{
    for(int i=n-1;i>index;i--){
        array[i] = array[i-1];
    }
    array[index] = value;
    return;
}

void E_command(int array_queue[], int E_id, int classes[], int student[], int n)
{
    int E_class=find_class(E_id,classes,student,n);
//    cout << E_class << endl;
    if(array_queue[0]==0){
        array_queue[0]=E_id;
        return;
    }
    for(int i=0;i<n;i++){
//        cout << find_class(array_queue[i],classes,student,n) << " " << find_class(array_queue[i+1],classes,student,n) << endl;
        if(E_class==find_class(array_queue[i],classes,student,n) && E_class!=find_class(array_queue[i+1],classes,student,n)){
            Insert(array_queue,i+1,E_id,n);
            return;
        }
        if(array_queue[i]==0){
            array_queue[i]=E_id;
            return;
        }
    }
    return;
}

void D_command(int qarray[], int result[], int n)
{
    int d=qarray[0];
    for(int i=0;i<n-1;i++){
        qarray[i]=qarray[i+1];
    }
    qarray[n-1]=0;
    for(int i=0;i<n;i++){
        if(result[i]==0){
            result[i]=d;
            return;
        }
    }
}

int main()
{
    int c, s;
    cin >> c >> s;
    int classes[s], student[s];
    for(int i=0;i<s;i++){
        cin >> classes[i] >> student[i];
    }
    char sign;
    int E_id;
    int result[s];
    int array_queue[s];
    for(int i=0;i<s;i++){
        result[i]=0;
        array_queue[i]=0;
    }
//    for(int i=0;i<s;i++){
//        cout << classes[i] << " ";
//    }cout << endl;
//    int classs;
//    cin >> classs;
//    cout << find_class(classs,classes,student,s);


    do{
        cin >> sign;
        if(sign=='E'){
            cin >> E_id;
            E_command(array_queue, E_id, classes, student, s);
        }
        if(sign=='D'){
            D_command(array_queue, result, s);
        }
//        for(int i=0;i<s;i++){
//            cout << array_queue[i] << " ";
//        }cout << endl;
    }while(sign!='X');
    if(result[0]==0){
        cout << "empty";
        return 0;
    }
    for(int i=0;i<s;i++){
//        cout << result[i] << " ";
        if(result[i]!=0){
            cout << result[i] <<endl;
        }
    }
    cout << 0 << endl;
    return 0;
}
