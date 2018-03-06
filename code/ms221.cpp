enum Status {Valid = 0, InValid};

int runStatus = Valid;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
        {
        	return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int pre = 0;
        int res = 0;
        vector<int> dp(m + 1, 0);
        for(int j = 0; j < n; j++)
        {
        	for(int i = 1; i <= m; i++)
        	{	
        		int tmp = dp[i];
        		if(matrix[i - 1][j] == '1')
        		{
        			dp[i] = min(dp[i - 1], min(tmp, pre)) + 1;
        			res = max(dp[i], res);
        		}
        		else if(matrix[i - 1][j] == '0')
        		{
        			dp[i] = 0;
        		}
        		else
        		{
        			runStatus = InValid;
        			return 0;
        		}
        		pre = tmp;
        	}
        }
        return res * res;
    }
};