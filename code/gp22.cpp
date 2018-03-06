#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n) {
    	vector<string> result;
    	root(result, n);
    	return result;
    }

    void root(vector<string>& result, int n)
    {
    	int m = n;
    	if(n == 0)
    	{
    		return;
    	}
    	string tmp = "";
    	forword(result, m, n, tmp);
    	if(m < n) back(result, m, n, tmp);
    }

    void forword(vector<string>& result, int m, int n, string tmp)
    {
    	tmp += '(';
    	m = m - 1;
		if(m > 0) forword(result, m, n, tmp);
    	if(m < n) back(result, m, n, tmp);
    }

    void back(vector<string>& result, int m, int n, string tmp)
    {
    	tmp += ')';
    	n = n - 1;
		if(m > 0) forword(result, m, n, tmp);
    	if(m < n) back(result, m, n, tmp);
    	if(n == 0)
    	{
    		result.push_back(tmp);
    	}
    }
};

int main()
{
	int n = 3;
	vector<string> result = Solution().generateParenthesis(n);  
	for(auto it = result.begin(); it != result.end(); it++)
	{
		cout << *it << endl;
	}
}