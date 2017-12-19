#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = triangle.size();
        for(int i = height - 2; i >= 0; i--)
        {
        	int tmp;
        	int n = triangle[i].size();
        	for(int j = 0; j < n; j++)
        	{
        		tmp = min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        		triangle[i][j] = triangle[i][j] + tmp;
        	}
        }
        return triangle[0][0];
    }
};

int main()
{
	vector<vector<int>> triangle = {{2}, {3,4}, {6,5,7}, {4,1,8,3}};
	int min = Solution().minimumTotal(triangle);
	cout << min << endl;
	return 0;
}