#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int i;
        for(i = 0; i < n; i++)
        {
        	if(nums[i] == target)
        	{
        		return true;
        	}
        	if( i != 0 )
        	{
        		if(nums[i] < nums[i - 1])
        		{
        			break;
        		}
        	}
        }
        if(i == n)
        {
        	return -1;
        }
        int mid = findMid(nums, i + 1, n - 1, target);
        if(mid != -1)
        {
            return true;
        }
        return false;
    }

    int findMid(vector<int>& nums, int start, int end, int target)
    {
    	if(start > end)
    	{
    		return -1;
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
	vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
	int target = 10;
	bool result = Solution().search(nums, target);
	cout << result << endl;
	return 0;
}