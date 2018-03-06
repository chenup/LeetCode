#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows == 0)
        {
        	return result;
        }
        int n = 1;
        while(n <= numRows)
        {
        	vector<int> tmp;
        	tmp.push_back(1);
        	for(int i = 2; i < n; i++)
        	{
        		tmp.push_back(result[n - 2][i - 2] + result[n - 2][i - 1]);
        	}
        	if(n > 1)
        	{
        		tmp.push_back(1);
        	}
      		result.push_back(tmp);
      		n++;
        }
        return result;
    }
};

int main()
{
	vector<vector<int>> result;
	int n = 5;
	result = Solution().generate(n);
	for(auto it = result.begin(); it != result.end(); it++)
	{
		for(auto itt = (*it).begin(); itt != (*it).end(); itt++)
		{
			cout << *itt << endl;
		}
	}
	return 0;
}