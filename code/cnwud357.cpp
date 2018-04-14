class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(11, 0);
        dp[0] = 1;
        dp[1] = 10;
        dp[2] = 10 + 9 * 9;
        for(int i = 3; i <= n; i++)
        {
            if(10 - i + 1 <= 0)
            {
                return dp[i - 1];
            }
            else
            {
               dp[i] = (dp[i - 1] - dp[i - 2]) * (10 - i + 1) + dp[i - 1]; 
            }
        }
        return dp[n];
    }
};