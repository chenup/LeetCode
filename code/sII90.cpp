#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp;
        result.push_back(tmp);
        sort(nums.begin(), nums.end());
        func(result, nums, tmp, 0);
        return result;
    }
    void func(vector<vector<int>>& result, vector<int>& nums, vector<int>& tmp, int k)
    {
    	for(int i = k; i < nums.size(); i++)
    	{
    		if(i != k && nums[i] == nums[i - 1])
    		{
    			continue;
    		}
    		tmp.push_back(nums[i]);
    		result.push_back(tmp);
    		func(result, nums, tmp, i + 1);
    		tmp.pop_back();
    	}
    }
};

int main()
{
	vector<int> nums = {1, 2, 2, 4};
	vector<vector<int>> result = Solution().subsetsWithDup(nums);
	for(auto v : result)
	{
		for(auto it : v)
		{
			cout << it << " "; 
		}
		cout << endl;
	}
	return 0;
}