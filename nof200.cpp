class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int sum = 0;
        int m = grid.size();
        if(m == 0)
        {
        	return sum;
        }
        int n = grid[0].size();
        vector<bool> tmp(n, false);
        vector<vector<bool>> table(m, tmp);
        for(int i = 0; i < m; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		if(!table[i][j] && grid[i][j] == '1')
        		{
        			helper(grid, table, i, j);
                    	//cout << i << " " << j <<endl;
        			sum++;
        		}
        	}
        }
        return sum;
    }

    void goUp(vector<vector<char>>& grid, vector<vector<bool>>& table, int i, int j)
    {
    	if(i < 0)
    	{
    		return;
    	}
    	if(table[i][j])
    	{
    		return;
    	}
    	table[i][j] = true;
    	if(grid[i][j] == '1')
    	{
    		goUp(grid, table, i - 1, j);
    		goLeft(grid, table, i, j - 1);
    		goRight(grid, table, i, j + 1);
    	}
    	
    }

    void goDown(vector<vector<char>>& grid, vector<vector<bool>>& table, int i, int j)
    {
    	int m = table.size(); 
    	if(i >= m)
    	{
    		return;
    	}
    	if(table[i][j])
    	{
    		return;
    	}
    	table[i][j] = true;
    	if(grid[i][j] == '1')
    	{
    		goDown(grid, table, i + 1, j);
    		goLeft(grid, table, i, j - 1);
    		goRight(grid, table, i, j + 1);
    	}
    	
    }

    void goLeft(vector<vector<char>>& grid, vector<vector<bool>>& table, int i, int j)
    { 
    	if(j < 0)
    	{
    		return;
    	}
    	if(table[i][j])
    	{
    		return;
    	}
    	table[i][j] = true;
    	if(grid[i][j] == '1')
    	{
    		goUp(grid, table, i - 1, j);
    		goDown(grid, table, i + 1, j);
    		goLeft(grid, table, i, j - 1);
    	}
    	
    }

    void goRight(vector<vector<char>>& grid, vector<vector<bool>>& table, int i, int j)
    {
    	int n = table[0].size(); 
    	if(j >= n)
    	{
    		return;
    	}
    	if(table[i][j])
    	{
    		return;
    	}
    	table[i][j] = true;
    	if(grid[i][j] == '1')
    	{
    		goUp(grid, table, i - 1, j);
    		goDown(grid, table, i + 1, j);
    		goRight(grid, table, i, j + 1);
    	}
    	
    }
    void helper(vector<vector<char>>& grid, vector<vector<bool>>& table, int i, int j)
    {
    	table[i][j] = true;
    	if(grid[i][j] == '1')
    	{
    		goUp(grid, table, i - 1, j);
    		goDown(grid, table, i + 1, j);
    		goLeft(grid, table, i, j - 1);
    		goRight(grid, table, i, j + 1);
    	}
    	
    }
};
