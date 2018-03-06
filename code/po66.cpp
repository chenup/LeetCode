#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        vector<int> result;
        for(auto it = digits.end() - 1; it >= digits.begin(); it--)
        {
        	if(*it == 9 && c == 1)
        	{
        		result.insert(result.begin(), 0);
        		c = 1;
        	}
        	else
        	{
        		result.insert(result.begin(), *it + c);
        		c = 0;
        	}
        }
        if(c == 1)
        {
        	result.insert(result.begin(), 1);
        }
        return result;
    }
};

int main()
{
	vector<int> digits = {0};
	vector<int> result = Solution().plusOne(digits);
	for(auto v : result)
	{
		cout << v << endl;
	}
	return 0;
}