class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
        {
        	return false;
        }
        if(matrix[0][0] > target || matrix.back().back() < target)
        {
        	return false;
        }
        int i = matrix.size() - 1;
        int j = 0;
        while(true)
        {
        	if(matrix[i][j] == target)
        	{
        		return true;
        	}
        	else if(matrix[i][j] > target)
        	{
        		i--;
        	}
        	else
        	{
        		j++;
        	}
        	if(i < 0 || j == matrix[0].size())
        	{
        		return false;
        	}
        }
    }
};