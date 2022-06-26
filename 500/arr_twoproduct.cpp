#include<bits/stdc++.h>
using namespace std;
/*

Given an integer array, find a pair with the maximum product in it.

Each input can have multiple solutions. The output should match with either one of them.

Input : [-10, -3, 5, 6, -2]
Output: (-10, -3) or (-3, -10) or (5, 6) or (6, 5)

Input : [-4, 3, 2, 7, -5]
Output: (3, 7) or (7, 3)

If no pair exists, the solution should return the pair (-1, -1).

Input : [1]
Output: (-1, -1)

*/

class Solution
{
public:
	pair<int,int> findPair(vector<int> const &nums)
	{
		pair<int,int> p;
		int max1 = nums[0], max2 = INT_MIN;
		int min1 = nums[0], min2 = INT_MAX;
		for(int i=1;i<nums.size();i++){
			if(nums[i]>max1){
				max2=max1;
				max1=nums[i];
			} else if(nums[i]>max2){
				max2=nums[i];
			}
			if(nums[i]<min1){
				min2=min1;
				min1=nums[i];
			} else if(nums[i]<min2){
				min2 = nums[i];
			}
		}
		if(max1*max2 > min1*min2){
			p.first = max1;
			p.second = max2;
			return p;
		} else {
			p.first = min1;
			p.second = min2;
			return p;
		}
	}
};

int main()
{
    vector<int> v = {-10, -3, 5, 6, -2};
    Solution ob;

    pair<int, int> p = ob.findPair(v);
    cout << p.first << " "<< p.second;
}

