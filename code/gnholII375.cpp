class Solution 
{
public:
    int getMoneyAmount(int n) 
    {
    	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    	for(int i = 2; i <= n; i++)
    	{
    		for(int j = i - 1; j >= 1; j--)
    		{
    			int global_min = INT_MAX;
    			for(int k = j + 1; k < i; k++)
    			{
    				int local_max = k + max(dp[j][k - 1], dp[k + 1][i]);
    				if(global_min > local_max)
    				{
    					global_min = local_max;
    				}
    			}
    			dp[j][i] = (i == j + 1) ? j : global_min;
    		}
    	}	  
    	return dp[1][n];      
    }
};