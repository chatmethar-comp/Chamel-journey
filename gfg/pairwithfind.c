#include<stdio.h>
//#include<algorithm>
void findpair(int num[], int n, int target)
{
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(num[i]+num[j]==target){
                printf("Pair found (%d, %d)\n", num[i], num[j]);
                return;
            }
        }
    }
    printf("Pair not found\n");
}

void findpair2(int num[], int n, int target)
{
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(num[i]>num[j]){
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    //sort(num, num+m);
    int low=0;
    int high=n-1;
    while(low<high){
        if(num[low]+num[high]==target){
            printf("Pair found (%d, %d)", num[low], num[high]);
        }
        if(num[low]+num[high]>target){
            high--;
        } else {
            low++;
        }
    }
}

int main()
{
    int num[] = {8, 7, 2, 5, 3, 1};
    int target = 10;
    int n = sizeof(num)/sizeof(num[0]);
    findpair(num, n, target);
    findpair2(num, n, target);
    return 0;
}
