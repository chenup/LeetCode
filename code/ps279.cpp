/*
class Solution {
public:
    int numSquares(int n) {
        while(n % 4 == 0)
        {
        	n /= 4;
        }
        if(n % 8 == 7)
        {
        	return 4;
        }
        int a = 0;
        for(; a * a <= n; a++)
        {
        	int b = sqrt(n - a * a);
        	if((a * a + b * b) == n)
        	{
        		return !!a + !!b;
        	}
        }
        return 3;
    }
};
*/
class Solution {
public:
    int numSquares(int n) {
    	vector<int> dp(n + 1, 5);
    	dp[0] = 0;
    	for(int a = 0; a <= n; a++)
    	{
    		for(int b = 1; a + b * b <= n; b++)
    		{
    			dp[a + b * b] = min(dp[a] + 1, dp[a + b * b]);
    		}
    	}
    	return dp.back();
    }
};
