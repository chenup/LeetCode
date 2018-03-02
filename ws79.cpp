#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
		if(word == "")
        {
        	return true;
        }
        int m = board.size();
        if(m == 0)
        {
        	return false;
        }
        int n = board[0].size();
        int l = word.size();
        vector<int> path;
        for(int i = 0; i < m; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		if(board[i][j] == word[0])
        		{
        			cout << board[i][j];
        			int idx = i * n + j;
        			path.push_back(idx);
        			if(toLeft(board, path, word, i, j - 1, 1) || toUp(board, path, word, i - 1, j, 1) || toRight(board, path, word, i, j + 1, 1) || toDown(board, path, word, i + 1, j, 1))
        			{
        				return true;
        			}
        			path.pop_back();
        		}
        	}
        }
        return false;
    }

    bool toLeft(vector<vector<char>>& board, vector<int>& path, string word, int i, int j, int k)
    {
    	int m = board.size();
        int n = board[0].size();
        int l = word.size();
        int idx = i * n + j;
        if(k == l)
        {
        	return true;
        }
        if(j < 0)
        {
        	return false;
        }
 		if(find(path.begin(), path.end(), idx) != path.end())
 		{
 			return false;
 		}
 		if(board[i][j] != word[k])
 		{
 			return false;
 		}
 		path.push_back(idx);
        if(toLeft(board, path, word, i, j - 1, k + 1) || toUp(board, path, word, i - 1, j, k + 1) || toDown(board, path, word, i + 1, j, k + 1))
		{
			return true;
		}
		path.pop_back();
        return false;
    }

    bool toUp(vector<vector<char>>& board,  vector<int>& path, string word, int i, int j, int k)
    {
    	int m = board.size();
        int n = board[0].size();
        int l = word.size();
        int idx = i * n + j;
        if(k == l)
        {
        	return true;
        }
        if(i < 0)
        {
        	return false;
        }
 		if(find(path.begin(), path.end(), idx) != path.end())
 		{
 			return false;
 		}
 		if(board[i][j] != word[k])
 		{
 			return false;
 		}
 		path.push_back(idx);
        if(toLeft(board, path, word, i - 1, j, k + 1) || toUp(board, path, word, i, j - 1, k + 1) || toRight(board, path, word, i + 1, j, k + 1))
		{
			return true;
		}
		path.pop_back();
        return false;
    }

    bool toRight(vector<vector<char>>& board,  vector<int>& path, string word, int i, int j, int k)
    {
    	int m = board.size();
        int n = board[0].size();
        int l = word.size();
        int idx = i * n + j;
        if(k == l)
        {
        	return true;
        }
        if(j >= n)
        {
        	return false;
        }
 		if(find(path.begin(), path.end(), idx) != path.end())
 		{
 			return false;
 		}
 		if(board[i][j] != word[k])
 		{
 			return false;
 		}
 		path.push_back(idx);
        if(toUp(board, path, word, i - 1, j, k + 1) || toRight(board, path, word, i, j + 1, k + 1) || toDown(board, path, word, i + 1, j, k + 1))
		{
			return true;
		}
		path.pop_back();
        return false;
    }

     bool toDown(vector<vector<char>>& board,  vector<int>& path, string word, int i, int j, int k)
    {
    	int m = board.size();
        int n = board[0].size();
        int l = word.size();
        int idx = i * n + j;
        if(k == l)
        {
        	return true;
        }
        if(i >= m)
        {
        	return false;
        }
 		if(find(path.begin(), path.end(), idx) != path.end())
 		{
 			return false;
 		}
 		if(board[i][j] != word[k])
 		{
 			return false;
 		}
 		path.push_back(idx);
        if(toLeft(board, path, word, i, j - 1, k + 1) || toRight(board, path, word, i, j + 1, k + 1) || toDown(board, path, word, i + 1, j, k + 1))
		{
			return true;
		}
		path.pop_back();
        return false;
    }

};
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty())
            return false;
        int rows = board.size(), cols = board[0].size();
        int len = 0;
        bool* visit = new bool[rows*cols];
        memset(visit, 0, rows*cols);
        for (int row = 0; row < rows;++row) {
            for (int col = 0; col < cols;++col) {
                if (hasWord(board, rows, cols, row, col, word, len, visit))
                    return true;
            }
        }
        delete[] visit;
        return false;
    }

    bool hasWord(vector<vector<char>>& board, int rows, int cols, int row, int col, string word, int& len, bool* visit) {
        if (word[len] == '\0')
            return true;
        bool hasword = false;
        if ((row >= 0) && (row < rows) && (col >= 0) && (col < cols) && (board[row][col] == word[len]) && !visit[row*cols + col])
        {
            ++len;
            visit[row*cols + col] = true;
            hasword = hasWord(board, rows, cols, row - 1, col, word, len, visit) || hasWord(board, rows, cols, row, col + 1, word, len, visit) ||
                hasWord(board, rows, cols, row + 1, col, word, len, visit) || hasWord(board, rows, cols, row, col - 1, word, len, visit);
            if (!hasword) {
                --len;
                visit[row*cols + col] = false;
            }
        }
        return hasword;
    }
};
int main()
{
	vector<vector<char>> board = {{"a", "b"}, {"c", "d"}};
	string word = "cdba";
	bool result = Solution().exist(board, word);
	cout << result << endl;
	return 0;
}