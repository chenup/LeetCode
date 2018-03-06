#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int uniquePaths(int m, int n) {
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
        	paths[1][i] = 1;
		}
		for(int j = 1; j <= M; j++)
        {
        	paths[j][1] = 1;
		}
        int result = getPaths(paths, m, n);
        return result;
    }

    int getPaths(vector<vector<int>>& paths, int m, int n)
    {
    	if(paths[m][n] == -1)
    	{
    		paths[m][n] = getPaths(paths, m, n - 1) + getPaths(paths, m - 1, n);
    	}
    	return paths[m][n];
    }
};

int main()
{
	int m = 2;
	int n = 1;
	int result = Solution().uniquePaths(m, n);
	cout << result << endl;
	return 0;
}