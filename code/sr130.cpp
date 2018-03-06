class Solution {
public:
    void solve(vector<vector<char>>& board) {
  		int m = board.size();
  		if(m == 0)
  		{
  			return;
  		}
  		int n = board[0].size();
  		vector<int> tmp(n, 0);
  		vector<vector<int>> vec(m, tmp);
  		for(int i = 0; i < m; i++)
  		{
  			helper(vec, board, i, 0, m, n);
  		}
  		for(int i = 0; i < m; i++)
  		{
  			helper(vec, board, i, n - 1, m, n);
  		}
  		for(int j = 0; j < n; j++)
  		{
  			helper(vec, board, 0, j, m, n);
  		}
  		for(int j = 0; j < n; j++)
  		{
  			helper(vec, board, m - 1, j, m, n);
  		}
  		for(int i = 1; i < m - 1; i++)
  		{
  			for(int j = 1; j < n - 1; j++)
  			{
  				if(vec[i][j] == 0 && board[i][j] == 'O')
  				{
  					board[i][j] = 'X';
  				}
  			}
  		}            
    }

    void helper(vector<vector<int>>& vec, vector<vector<char>>& board, int i, int j, int m, int n)
    {
    	if(i < 0 || i >= m || j < 0 || j >= n)
    	{
    		return;
    	}
    	if(vec[i][j] == 1)
    	{
    		return;
    	}
    	else
    	{
    		vec[i][j] = 1;
    		if(board[i][j] == 'O')
    		{
    			helper(vec, board, i - 1, j, m, n);
    			helper(vec, board, i + 1, j, m, n);
    			helper(vec, board, i, j - 1, m, n);
    			helper(vec, board, i, j + 1, m, n);
    		}
    	}
    }
};