class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int tmp = nums[0];
        for(auto it : nums)
        {
        	if(tmp == it)
        	{
        		count++;
        	}
        	else if(count == 1)
        	{
        		return tmp;
        	}
        	else
        	{
        		count = 1;
        		tmp = it;
        	}
        }
        return tmp;
    }
};