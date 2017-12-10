#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = *(nums.begin());
        int start = 0, end = 0, sum = max;
        int c = sum;
        for(auto it = nums.begin() + 1;it != nums.end();it++)
        {
        	c += *it;
        	if(*it > c)
        	{
        		if(sum > max)
        		{
        			max = sum;
        		}
        		start = it - nums.begin();
        		end = it - nums.begin();
        		sum = *it;
        		c = sum;
        	}
        	if(c > sum)
        	{
        		sum = c;
        		end = it - nums.begin();
        	}
        	
        }
        if(sum > max)
        {
        	max = sum;
        }
        return max;
    }
};

int main()
{
	vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
	int result = Solution().maxSubArray(nums);
	cout << result;
	return 0;
}