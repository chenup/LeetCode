class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> res;
        int sum = 1;
        int flag = 0;
        int n = nums.size();
        if(n < 2)
        {
        	return n;
        }
        for(int i = 1; i < n; i++)
        {
        	res.push_back(nums[i] - nums[i - 1]);
        }
        for(auto it : res)
        {
        	if(flag == 0)
        	{
        		if(it > 0)
        		{
        			sum++;
        			flag = -1;
        		}
        		else if(it < 0)
        		{
        			sum++;
        			flag = 1;
        		}
        	}
        	else if(flag == 1)
        	{
        		if(it > 0)
        		{
        			sum++;
        			flag = -1;
        		}
        	}
        	else
        	{
        		if(it < 0)
        		{
        			sum++;
        			flag = 1;
        		}
        	}
        }
        return sum;
    }
};