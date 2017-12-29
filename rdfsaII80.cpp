#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
        {
        	return 0;
        }
        int result = 1;
        int tmpv = nums[0];
        int tmpc = 0;
        for(auto it = nums.begin(); it != nums.end();)
        {
        	if(*it != tmpv)
        	{
        		result += tmpc;
        		tmpc = 1;
        		tmpv = *it;
        		it++;
        	}
        	else
        	{
        		if(tmpc == 2)
        		{
        			it = nums.erase(it);
        		}
        		else
        		{
        			tmpc++;
        			it++;
        		}
        	}
        }
        return result;
    }
};

int main()
{
	vector<int> nums = {1, 1, 2, 2, 2, 5};
	int result = Solution().removeDuplicates(nums);
	for(auto v : nums)
	{
		cout << v << endl;
	}
	cout << result << endl;
	return 0;
}