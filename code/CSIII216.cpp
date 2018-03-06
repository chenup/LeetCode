class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res, tmp, k, n, 0);
        return res;
    }

    void dfs(vector<vector<int>>& res,  vector<int>& tmp, int k, int n, int m)
    {
    	if(k == 0)
    	{
    		if(n > 0)
    		{
    			return;
    		}
    		else if(n == 0)
    		{
    			res.push_back(tmp);
    		}
    		
    	}
    	for(int i = m + 1; i <= 9; i++)
    	{
    		if(n < i)
    		{
    			break;
    		}
    		tmp.push_back(i);
    		dfs(res, tmp, k - 1, n - i, i);
    		tmp.pop_back();
    	}
    }
};