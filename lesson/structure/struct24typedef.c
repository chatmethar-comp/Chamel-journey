#include<stdio.h>
#include<limits.h>
typedef struct
{
    char name[20];
    int age;
} PERSON;

PERSON assign()
{
    PERSON man;
    scanf("%s %d", man.name, &man.age);
    return man;
}

int oldest(PERSON g[])
{
    int old=INT_MIN;
    for(int i=0;i<5;i++){
        old = (old<g[i].age) ? g[i].age : old;
    }
    return old;
}

int main()
{
    PERSON people[5];
    for(int i=0;i<5;i++){
        people[i] = assign();
    }
    printf("%d", oldest(people));
    return 0;
}
