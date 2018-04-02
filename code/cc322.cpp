//迭代，数组
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
        	for(int j = 0; j < coins.size(); j++)
        	{
        		int tmp = i - coins[j];
        		if(tmp < 0)
        		{
        			continue;
        		}
        		dp[i] = min(dp[i], dp[tmp] + 1);
        	}
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
    	
};

//递归，hash表
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> dp;
        dp[0] = 0;
        int res = helper(coins, dp, amount);
        return res == INT_MAX - 1 ? -1 : res;
    }
    
    int helper(vector<int>& coins, unordered_map<int, int>& dp, int amount)
    {
    	if(dp.find(amount) != dp.end())
    	{
    		return dp[amount];
    	}
    	dp[amount] = INT_MAX - 1;
    	for(int i = 0; i < coins.size(); i++)
    	{
    		int tmp = amount - coins[i];
    		if(tmp < 0)
    		{
    			continue;
    		}
    		dp[amount] = min(dp[amount], helper(coins, dp, tmp) + 1); 
    	}
    	return dp[amount];
    }
};