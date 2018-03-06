#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0)
        {
        	return false;
		}
        int n = matrix[0].size();
        int l = m * n;
        if(l == 0)
        {
        	return false;
        }
        return findMid(matrix, 0, l - 1, target);
    }

    bool findMid(vector<vector<int>>& matrix, int s, int e, int target)
    {
    	if(s > e)
    	{
    		return false;
    	}
		int mid = (s + e) / 2;
		int n = matrix[0].size();
		int i = mid / n;
		int j = mid % n;
		if(matrix[i][j] == target)
		{
			return true;
		}
		else if(matrix[i][j] > target)
		{
			return findMid(matrix, s, mid - 1, target);
		}
		else
		{
			return findMid(matrix, mid + 1, e, target);
		}
    }
};

int main()
{
	vector<vector<int>> matrix = {};
	int target = 0;
	bool result = Solution().searchMatrix(matrix, target);
	cout << result << endl;
	return 0;
}