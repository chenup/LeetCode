/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	int n = nums.size();
    	if(nums.size() == 0)
    	{
    		return 0;
    	} 
    	vector<int> maxs(n, 0);
    	for(int i = 0; i < n; i++)
    	{
    		int max = 1;
    		for(int j = 0; j < i; j++)
    		{
    			if(nums[i] > nums[j])
    			{
    				int tmp = maxs[j] + 1;
                    if(tmp > max)
                    {
                        max = tmp;
                    }
    			}
    		}
            maxs[i] = max;
    		
    	}
    	return *max_element(maxs.begin(), maxs.end());
    }
};
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	vector<int> ends;
    	for(auto n : nums)
    	{
    		auto it = lower_bound(ends.begin(), ends.end(), n);
    		if(it == ends.end())
    		{
    			ends.push_back(n);
    		}
    		else
    		{
    			*it = n;
    		}
    	}
    	return ends.size();    
    }
};