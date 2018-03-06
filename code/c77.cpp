#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> tmp;
        getCombine(result, 1, n, k, tmp);
        return result;
    }

    void getCombine(vector<vector<int>>& result, int s, int n, int k, vector<int>& tmp)
    {
    	if(k == 0)
    	{
    		result.push_back(tmp);
    		return;
    	}
    	for(int i = s; i <= n - k + 1; i++)
    	{
    		tmp.push_back(i);
    		getCombine(result, i + 1, n, k - 1, tmp);
    		tmp.pop_back();
    	}
    }
};

int main()
{
	int n = 4;
	int k = 2;
	vector<vector<int>> result = Solution().combine(n, k);
	for(auto it : result)
	{
		for(auto itt : it)
		{
			cout << itt << " ";
		}
		cout << endl;
	}
	return 0;
}