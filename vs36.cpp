#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    	int m = board.size();
    	if(m != 9)
    	{
    		return false;
    	}
    	int n = board[0].size();
    	if(n != 9)
    	{
    		return false;
    	}
        if(little(board)&&vertical(board)&&horizontal(board))
        {
        	return true;
        }
        return false;
    }

    bool little(vector<vector<char>>& board)
    {
    	for(int k = 0; k < 9; k++)
    	{
    		vector<int> tmp;
    		tmp.insert(tmp.begin(), 9, -1);
    		int a = k / 3;
    		int b = k % 3;
    		for(int i = 0; i < 3; i++)
    		{
    			for(int j = 0; j < 3; j++)
    			{
    				int t1 = k * 3 + i;
    				int t2 = k * 3 + j;
    				if(board[t1][t2] == '.')
	    			{
	    				continue;
	    			}
	    			else
	    			{
	    				int idx = board[t1][t2] - '0' - 1;
	    				if(tmp[idx] == -1)
	    				{
	    					tmp[idx] = 1;
	    				}
	    				else
	    				{
	    					return false;
	    				}
	    			}
    			}
    		}
    	}
    	return true;
    }

    bool horizontal(vector<vector<char>>& board)
    {
    	for(int i = 0; i < 9; i++)
    	{
    		vector<int> tmp;
    		tmp.insert(tmp.begin(), 9, -1);
    		for(int j = 0; j < 9; j++)
    		{
    			if(board[i][j] == '.')
    			{
    				continue;
    			}
    			else
    			{
    				int idx = board[i][j] - '0' - 1;
    				if(tmp[idx] == -1)
    				{
    					tmp[idx] = 1;
    				}
    				else
    				{
    					return false;
    				}
    			}
    		}
    	}
    	return true;
    }

    bool vertical(vector<vector<char>>& board)
    {

    	for(int i = 0; i < 9; i++)
    	{
    		vector<int> tmp;
    		tmp.insert(tmp.begin(), 9, -1);
    		for(int j = 0; j < 9; j++)
    		{
    			if(board[j][i] == '.')
    			{
    				continue;
    			}
    			else
    			{
    				int idx = board[j][i] - '0' - 1;
    				if(tmp[idx] == -1)
    				{
    					tmp[idx] = 1;
    				}
    				else
    				{
    					return false;
    				}
    			}
    		}
    	}
    	return true;
    }
};

int main()
{
	vector<vector<char>> board = {{".","8","7","6","5","4","3","2","1"},{"2",".",".",".",".",".",".",".","."},{"3",".",".",".",".",".",".",".","."},{"4",".",".",".",".",".",".",".","."},{"5",".",".",".",".",".",".",".","."},{"6",".",".",".",".",".",".",".","."},{"7",".",".",".",".",".",".",".","."},{"8",".",".",".",".",".",".",".","."},{"9",".",".",".",".",".",".",".","."},};
	bool result = Solution().isValidSudoku(board);
	cout << result << endl;

	return 0;
}