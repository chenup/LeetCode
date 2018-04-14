class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 0);
        vector<int> parent(n, 0);
        vector<int> res;
        int max = 0;
        int max_l = 0;
        for(int i = 0; i < n; i++)
        {
        	for(int j = i; j >= 0; j--)
        	{
        		if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
        		{
        			dp[i] = dp[j] + 1;
        			parent[i] = j;
                    if(max_l < dp[i])
                    {
                        max_l = dp[i];
                        max = i;
                    }
        		}
        	}
        }
        for(int i= 0; i < max_l; i++)
        {
        	res.push_back(nums[max]);
        	max = parent[max];
        }
        return res;
    }
};