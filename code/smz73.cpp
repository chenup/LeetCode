#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row;
        set<int> col;
        int i = 0;
        int j = 0;
        for(auto itr : matrix)
        {
        	j = 0;
        	for(auto itc : itr)
        	{
        		if(itc == 0)
        		{
        			row.insert(i);
        			col.insert(j);
        		}
        		j++;
        	}
        	i++;
        }
        for(auto it : row)
        {
        	for(int i = 0; i < matrix[0].size(); i++)
        	{
        		matrix[it][i] = 0;
        	}
        	
        }
        for(auto it : col)
        {
        	for(int i = 0; i < matrix.size(); i++)
        	{
        		matrix[i][it] = 0;
        	}
        }
    }
};

int main()
{
	vector<vector<int>> matrix = {{0, 1, 0}, {2, 3, 1}, {0, 0, 0}};
	Solution().setZeroes(matrix);
	for(auto it : matrix)
	{
		for(auto itt : it)
		{
			cout << itt << " ";
		}
		cout << endl;
	}
	return 0;
}