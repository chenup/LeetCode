class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if(!m)
        {
        	return;
        }
        int n = board[0].size();
        if(!n)
        {
        	return;
        }
        for(int i = 0; i < m; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		int lives = 0;
        		for(int p = max(0, i - 1); p <= min(i + 1, m - 1); p++)
        		{
        			for(int q = max(0, j - 1); q <= min(j + 1, n - 1); q++)
        			{
        				lives += board[p][q] & 1;
        			}
        		}
                
        		if(lives == 3 || lives - board[i][j] == 3)
        		{
        			board[i][j] |= 2;
        		}
        	}
        }
        for(int i = 0; i < m; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		board[i][j] = board[i][j] >> 1;
        	}
        }
    }
};