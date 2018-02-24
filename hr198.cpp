class Solution {
public:
    int rob(vector<int>& nums) {
    	int tmp = 0;
    	int max = 0;
    	for(int i = 0; i < nums.size(); i++)
    	{
    		int a = tmp + nums[i];
    		int b = max;
    		tmp = b;
    		max = a > b ? a : b;
    	}
        return max;
    }
};