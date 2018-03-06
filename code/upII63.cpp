#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
		vector<vector<int>> paths;
        vector<int> tmp;
        int M, N;
        if(m == 0)
        {
        	M = 1;
		}
		else
		{
			M = m;
		}
		if(n == 0)
        {
        	N = 1;
		}
		else
		{
			N = n;
		}
        tmp.insert(tmp.end(), N + 1, -1);
        for(int i = 0; i <= M; i++)
        {
        	paths.push_back(tmp);
        }
        for(int i = 0; i <= N; i++)
        {
        	paths[0][i] = 0;
		}
		for(int j = 0; j <= M; j++)
        {
        	paths[j][0] = 0;
		}
		for(int i = 1; i <= N; i++)
        {
        	if(obstacleGrid[0][i - 1] == 1)
        	{
        		for(int j = i; j <= N; j++)
        		{
        			paths[1][j] = 0;
        		}
        		break;
        	}
        	paths[1][i] = 1;

		}
		for(int j = 1; j <= M; j++)
        {
        	if(obstacleGrid[j - 1][0] == 1)
        	{
        		for(int i = j; i <= M; i++)
        		{
        			paths[i][1] = 0;
        		}
        		break;
        	}
        	paths[j][1] = 1;
		}
        int result = getPaths(obstacleGrid, paths, m, n);
        return result;
    }

    int getPaths(vector<vector<int>>& obstacleGrid, vector<vector<int>>& paths, int m, int n)
    {
    	if(paths[m][n] == -1)
    	{
    		if(obstacleGrid[m - 1][n - 1] == 1)
    		{
    			paths[m][n] = 0;
    		}
    		else
    		{
    			paths[m][n] = getPaths(obstacleGrid, paths, m, n - 1) + getPaths(obstacleGrid, paths, m - 1, n);
    		}
    		
    	}
    	return paths[m][n];
    }
};

int main()
{
	vector<vector<int>> obstacleGrid;
	vector<int> row1 = {0, 0, 0};
	vector<int> row2 = {0, 1, 0};
	vector<int> row3 = {0, 0, 0};
	obstacleGrid.push_back(row1);
	obstacleGrid.push_back(row2);
	obstacleGrid.push_back(row3);
	int result = Solution().uniquePathsWithObstacles(obstacleGrid);
	cout << result << endl;
	return 0;
} 