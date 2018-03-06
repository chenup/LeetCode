#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> result;
        result.push_back(1);
        result.push_back(1);
        for(int i = 2; i <= n; i++)
        {
        	int tmp = 0;
        	for(int j = 0; j <= i - 1; j++)
        	{
        		tmp += result[j] * result[i - 1 - j];
        	}
        	result.push_back(tmp);
        }
        return result[n];
    }
};

int main()
{
	int n = 9;
	int result = Solution().numTrees(n);
	cout << result << endl;
	return 0;
}