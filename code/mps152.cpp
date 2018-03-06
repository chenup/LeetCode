#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int>& nums) 
    {
    	int neg = 0;
    	int a = 1;
    	int x = 1;
    	int max = 0;
    	int flag = 0;
    	if(nums.size() == 1)
    	{
    		return nums[0];
    	}
    	for(auto it : nums)
    	{
    		if(it == 0)
    		{
    			flag = 0;
    			x = 1;
    			a = 1;
    		}
    		else if(it < 0)
    		{
    			flag++;
    			if(flag == 1)
    			{
    				neg = it;
    				a = x;
    				x = 1;
    			}
    			else if(flag % 2 == 1)
    			{
    				x = x * it / a / neg;
    				if(x > max)
    				{
    					max = x;
    				}
    			}
    			else
    			{
    				x = x * it * neg * a;
    				if(x > max)
    				{
    					max = x;
    				}
    			}
    		}
    		else
    		{
    			x = x * it;
    			if(x > max)
    			{
    				max = x;
    			}
    		}
    	}
    	return max;
    }
};


int main(int argc, char const *argv[])
{
	vector<int> nums = {3, -2, 4, 0, 2, -5, -2, -4, 3, 0, 5};
	int res = Solution().maxProduct(nums);
	cout << res << endl;	
	return 0;
}