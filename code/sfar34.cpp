#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       	int start =	0;
       	int end = nums.size() - 1;
       	int q = findMid(nums, start, end, target);
       	vector<int> result;
       	if(q == -1 || nums[q] != target)
       	{
       		return {-1, -1};
       	}
       	int p = q;
       	while(p > 0)
       	{
       		if(nums[p - 1] != target)
       		{
       			break;
       		}
       		p--;
       	}
       	result.push_back(p);
       	p = q;
       	while(p < end)
       	{
       		if(nums[p + 1] != target)
       		{
       			break;
       		}
       		p++;
       	}
       	result.push_back(p);
       	return result;
    }

    int findMid(vector<int>& nums, int start, int end, int target)
    {
    	if(start > end)
    	{
    		return -1;
    	}
    	else if(start == end)
    	{
    		return start;
    	}
    	int mid = (start + end) / 2;
    	if(nums[mid] == target)
    	{
    		return mid;
    	}
    	else if(nums[mid] < target)
    	{
    		return findMid(nums, mid + 1, end, target);
    	}
    	else
    	{
    		return findMid(nums, start, mid - 1, target);
    	}
    }
};

int main()
{
	vector<int> nums = {5, 6, 7, 8, 8, 10};
	int target = 5;
	vector<int> result = Solution().searchRange(nums, target);
	for(auto it = result.begin(); it != result.end(); it++)
	{
		cout << *it << endl;
	}
	return 0;
}