#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
	{
        vector<vector<int>> result;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        fun(nums, tmp, result);
        return result;
    }

    void fun(vector<int>& nums, vector<int>& tmp, vector<vector<int>> &result)
    {
    	if(nums.size() == 0)
    	{
    		if(tmp.size() != 0)
    		{
    			result.push_back(tmp);
    		}
    		return;
    	}
    	for(auto it = nums.begin(); it != nums.end(); it++)
    	{
    		int num = *it;
    		if(it != nums.begin())
    		{
    			if(*(it - 1) == num)
    			{
    				continue;
    			}
    		}
    		tmp.push_back(num);
    		it = nums.erase(it);
    		fun(nums, tmp, result);
    		tmp.pop_back();
    		it = nums.insert(it, num);
    	}
    	return;
    }
};

int main()
{
	vector<int> nums = {1, 2, 1};
	vector<vector<int>> result = Solution().permuteUnique(nums);
	for(auto it = result.begin(); it != result.end(); it++)
	{
		for(auto itt = (*it).begin(); itt != (*it).end(); itt++)
		{
			cout << *itt << " ";
		}
		cout << endl;
	}
	return 0;
}