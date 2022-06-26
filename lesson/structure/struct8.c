#include<stdio.h>
struct date
{
    int day;
    int month;
    int year;
};

struct info
{
    char name[40];
    long id;
    struct date birthdate;
};

int main()
{
    struct info person;
    printf("Please enter your first name, last name\n");
    gets(person.name);
    printf("Please enter your identical number\n");
    scanf("%ld", &person.id);
    printf("Please enter day, month, year of birth\n");
    scanf("%d %d %d",&person.birthdate.day, &person.birthdate.month, &person.birthdate.year);
    printf("Name : %s\n",person.name);
    printf("ID : %ld\n", person.id);
    printf("Birthday : %d %d %d",person.birthdate.day, person.birthdate.month,person.birthdate.year);
    return 0;
}




