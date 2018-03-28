class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0 || matrix[0].size() == 0)
        {
        	return res;
        }
        helper(matrix, res, true, 0, 0);
        return res;
    }

    void helper(vector<vector<int>>& matrix, vector<int>& res, bool dir, int i, int j)
    {
    	if(i == matrix.size() - 1 && j == matrix[0].size() - 1)
    	{
    		res.push_back(matrix[i][j]);
    		return;
    	}
    	if(dir)
    	{
	    	while(true)
	    	{
	    		res.push_back(matrix[i][j]);
	    		if(i - 1 < 0 || j + 1 >= matrix[0].size())
	    		{
	    			if(j + 1 >= matrix[0].size())
	    			{
	    				i += 1; 
	    			}
	    			else
	    			{
	    				j += 1;
	    			}
	    			break;
	    		}
	    		i -= 1;
	    		j += 1;
	    	}
	    }
    	else
    	{
    		while(true)
	    	{
	    		res.push_back(matrix[i][j]);
	    		if(i + 1 >= matrix.size() || j - 1 < 0) 
	    		{
	    			if(i + 1 >= matrix.size())
	    			{
	    				j += 1; 
	    			}
	    			else
	    			{
	    				i += 1;
	    			}
	    			break;
	    		}
	    		i += 1;
	    		j -= 1;
	    	}
    	}
    	helper(matrix, res, !dir, i, j); 	
    }
};

