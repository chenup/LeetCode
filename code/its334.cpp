class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
    	int m1 = INT_MAX;
    	int m2 = INT_MAX;
        for(auto a : nums)
        {
        	if( a <= m1)
        	{
        		m1 = a;
        	}
        	else if(a <= m2)
        	{
        		m2 = a;
        	}
        	else
        	{
        		return true;
        	}
        }
        return false;
    }
};

//用forward和backward数组
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
    	int n = nums.size();
        vector<int> f(n, 0);
        vector<int> b(n, 0);
        int min = INT_MAX;
        int max = INT_MIN;
        for(int i = 0; i < n; i++)
        {
        	if(nums[i] < min)
        	{
        		min = nums[i];
        	}
        	f[i] = min;
        }
        for(int i = n - 1; i >= 0; i--)
        {
        	if(nums[i] > max)
        	{
        		max = nums[i];
        	}
        	b[i] = max;
        }
        for(int i = 0; i < n; i++)
        {
        	if(nums[i] > f[i] && nums[i] < b[i])
        	{
        		return true;
        	}
        }
        return false;
    }
};
