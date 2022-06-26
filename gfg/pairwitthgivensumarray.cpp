#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

void pairNumTarget(int nums[],int n, int target)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            //cout << nums[i] << nums[j] << endl;
            if(nums[i]+nums[j]==target){
                cout << "Pair found (" << nums[i] << "," << nums[j] << ")" << endl;
                return;
            }
        }
    }
    cout << "Pair not found";
}

void pairfind2(int nums[],int n, int target)
{
    sort(nums, nums+n);

    int low = 0;
    int high = n-1;
    while(low < high){
        if(nums[low]+nums[high]==target){
            cout << "Pair found (" << nums[low] << ", " << nums[high] << ")" <<endl;
            return;
        }
        if(nums[low]+nums[high]<target){
            low++;
        } else {
            high--;
        }
    }
}

void findpairunodermap(int nums[], int n, int target)
{
    unordered_map<int, int> map;
    //cout << map.find(target) << endl;
    for(int i=0;i<n;i++){
        if(map.find(target-nums[i]) != map.end()){
            cout << "Pair found (" << nums[map[target - nums[i]]] << ", " << nums[i] << ")" << endl;
            return;
        }
        map[nums[i]] = i;
    }
}

int main()
{
    int nums[] = {8, 7, 2, 5, 3, 1};
    int target = 10;
    int n = sizeof(nums)/sizeof(nums[0]);
    //pairNumTarget(nums, n, target);
    //pairfind2(nums, n, target);
    findpairunodermap(nums, n, target);
    return 0;
}
