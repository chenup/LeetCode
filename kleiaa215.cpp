#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
   		int res = 0;
   		helper(nums, 0, nums.size() - 1, k, res);
   		return res;
    }

    void helper(vector<int>& nums, int lo, int hi, int k, int& res)
    {
    	if(lo > hi)
    	{
    		return;
    	}
    	int m = nums[lo];
    	int tmp = lo;
    	bool flag = true;
    	int left = lo + 1;
    	int right = hi;
    	while(left <= right)
    	{
    		if(flag)
    		{
    			if(nums[right] > m)
    			{
    				nums[tmp] = nums[right];
    				tmp = right;
    				right--;
    				flag = false;
    			}
    			else
    			{
    				right--;
    			}
    		}
    		else
    		{
    			if(nums[left] < m)
    			{
    				nums[tmp] = nums[left];
    				tmp = left;
    				left++;
    				flag = true;
    			}
    			else
    			{
    				left++;
    			}
    		}

    	}
    	nums[tmp] = m;
    	if(tmp > k - 1)
    	{
    		helper(nums, lo, tmp - 1, k, res);
    	}
    	else if(tmp < k - 1)
    	{
    		helper(nums, tmp + 1, hi, k, res);
    	}
    	else
    	{
    		res = m;
    	}
    	return;
    }
};
int main()
{
	vector<int> nums = {1};
	int k = 1;
	cout << Solution().findKthLargest(nums, k); 
	return 0;
}