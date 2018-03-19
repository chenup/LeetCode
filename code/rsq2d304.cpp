class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
    	int m, n;
        
    	if(matrix.size() > 0 && matrix[0].size() > 0)
    	{
            
    		m = matrix.size();
    		n = matrix[0].size();
    		cache = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
           
    		for(int j = 1; j <= n; j++)
    		{
    			for(int i = 1; i <= m; i++)
    			{
    				cache[i][j] = cache[i - 1][j] + matrix[i - 1][j - 1];
    			}

    		}
    		for(int i = 1; i <= m; i++)
    		{
    			for(int j = 1; j <= n; j++)
    			{
    				cache[i][j] = cache[i][j - 1] + cache[i][j];
    			}

    		}
    	}     
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return cache[row2 + 1][col2 + 1] + cache[row1][col1] - cache[row2 + 1][col1] - cache[row1][col2 + 1]; 
    }
private:
	vector<vector<int>> cache;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */