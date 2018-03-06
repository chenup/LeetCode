#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;
		int m = matrix.size();
		if(m == 0)
		{
			return result;
		}
		int n = matrix[0].size();
		if(n == 0)
		{
			return result;
		}
		moveRight(matrix, 0, 0, m, n, result);
		return result;
    }

    void moveRight(vector<vector<int>>& matrix, int i, int j, int m, int n, vector<int>& result)
    {
    	if(n == 0)
    	{
    		return;
    	}
    	for(int k = 0; k < n; k++)
    	{
    		result.push_back(matrix[i][j + k]);
    	}
    	moveDown(matrix, i + 1, j + n - 1, m - 1, n, result);
    }

    void moveDown(vector<vector<int>>& matrix, int i, int j, int m, int n, vector<int>& result)
    {
    	if(m == 0)
    	{
    		return;
    	}
    	for(int k = 0; k < m; k++)
    	{
    		result.push_back(matrix[i + k][j]);
    	}
    	moveLeft(matrix, i + m - 1, j - 1, m, n - 1, result);
    }

    void moveLeft(vector<vector<int>>& matrix, int i, int j, int m, int n, vector<int>& result)
    {
    	if(n == 0)
    	{
    		return;
    	}
    	for(int k = 0; k < n; k++)
    	{
    		result.push_back(matrix[i][j - k]);
    	}
    	moveUp(matrix, i - 1, j - n + 1, m - 1, n, result);
    }

    void moveUp(vector<vector<int>>& matrix, int i, int j, int m, int n, vector<int>& result)
    {
    	if(m == 0)
    	{
    		return;
    	}
    	for(int k = 0; k < m; k++)
    	{
    		result.push_back(matrix[i - k][j]);
    	}
    	moveRight(matrix, i - m + 1, j + 1, m, n - 1, result);
    }
};

int main()
{
	vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
	vector<int> result = Solution().spiralOrder(matrix);
	for(auto it = result.begin(); it != result.end(); it++)
	{
		cout << *it << endl;
	}
	return 0;
}