#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
    	int m = pow(2, n);
    	vector<int> result;
    	for(int i = 0; i < m; i++)
    	{
    		result.push_back(i ^ (i >> 1));
    	}
    	return result;
    }


};

int main()
{
	int n = 2;
	vector<int> result = Solution().grayCode(n);
	for(auto v : result)
	{
		cout << v << endl;
	}
	return 0;
}