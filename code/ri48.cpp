#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
   		int n = matrix.size();
   		for(int i = 0; i < n; i++)
   		{
			for(int j = 0; j < n; j++)
			{
				matrix[j].insert(matrix[j].end() - i, matrix[i][j]);
			}
			matrix[i].erase(matrix[i].begin(), matrix[i].begin() + n);
   		}
    }
};

int main()
{
	vector<vector<int>> matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
	Solution().rotate(matrix);
	for(auto it = matrix.begin(); it != matrix.end(); it++)
	{
		for(auto itt = (*it).begin(); itt != (*it).end(); itt++)
		{
			cout << *itt << " ";
		}
		cout << endl;
	}
	return 0;
}