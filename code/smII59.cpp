#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix;
        if(n == 0)
        {
        	return matrix;
        }
        vector<int> tmp;
        for(int i = 0; i < n; i++)
        {
        	tmp.push_back(0);
        }
        for(int j = 0; j < n; j++)
        {
    		matrix.push_back(tmp);
        }
        int count = 1;
        moveRight(matrix, 0, 0, n, n, count);
        return matrix;	
    }

    void moveRight(vector<vector<int>>& matrix, int i, int j, int m, int n, int count)
    {
    	if(n == 0)
    	{
    		return;
    	}
    	for(int k = 0; k < n; k++)
    	{
    		matrix[i][j + k] = count++;
    	}
    	moveDown(matrix, i + 1, j + n - 1, m - 1, n, count);
    }

    void moveDown(vector<vector<int>>& matrix, int i, int j, int m, int n, int count)
    {
    	if(m == 0)
    	{
    		return;
    	}
    	for(int k = 0; k < m; k++)
    	{
    		matrix[i + k][j] = count++;
    	}
    	moveLeft(matrix, i + m - 1, j - 1, m, n - 1, count);
    }

    void moveLeft(vector<vector<int>>& matrix, int i, int j, int m, int n, int count)
    {
    	if(n == 0)
    	{
    		return;
    	}
    	for(int k = 0; k < n; k++)
    	{
    		matrix[i][j - k] = count++;
    	}
    	moveUp(matrix, i - 1, j - n + 1, m - 1, n, count);
    }

    void moveUp(vector<vector<int>>& matrix, int i, int j, int m, int n, int count)
    {
    	if(m == 0)
    	{
    		return;
    	}
    	for(int k = 0; k < m; k++)
    	{
    		matrix[i - k][j] = count++;
    	}
    	moveRight(matrix, i - m + 1, j + 1, m, n - 1, count);
    }
};


int main()
{
	int n = 3;
	vector<vector<int>> result = Solution().generateMatrix(n);
	for(auto it = result.begin(); it != result.end(); it++)
	{
		for(auto itt = (*it).begin(); itt != (*it).end(); itt++)
		{
			cout << *itt << endl;
		}
	}
	return 0;
}
