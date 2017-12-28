#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


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

int main()
{
	vector<vector<char>> board = {{"a", "b"}, {"c", "d"}};
	string word = "cdba";
	bool result = Solution().exist(board, word);
	cout << result << endl;
	return 0;
}