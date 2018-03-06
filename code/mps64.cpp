#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
		vector<vector<int>> paths;
		vector<int> tmp;
        tmp.insert(tmp.end(), n, -1);
        for(int i = 0; i < m; i++)
        {
        	paths.push_back(tmp);
        }
        int result = getMinPath(grid, paths, m - 1, n - 1);
        return result;
    }

    int getMinPath(vector<vector<int>>& grid, vector<vector<int>>& paths, int m, int n)
    {
    	if(paths[m][n] == -1)
    	{
    		if(m == 0 || n == 0)
    		{
    			if(m == 0 && n == 0)
    			{
    				paths[0][0] = grid[0][0];
    			}
    			else if(m == 0)
    			{
    				paths[0][n] = getMinPath(grid, paths, 0, n - 1) + grid[0][n];
    			}
    			else
    			{
    				paths[m][0] = getMinPath(grid, paths, m - 1, 0) + grid[m][0];
    			}
    		}
    		else
    		{
    			paths[m][n] = min(getMinPath(grid, paths, m - 1, n), getMinPath(grid, paths, m, n - 1)) + grid[m][n];
    		}
    		
    	}
    	return paths[m][n];
    }
};

int main()
{
	vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
	int result = Solution().minPathSum(grid);
	cout << result << endl;
	return 0;
}