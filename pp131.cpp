#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        if(s.size() == 0)
        {
        	return result;
        }
        vector<string> tmp;
        helper(s, tmp, result);
        return result;
    }

    void helper(string s, vector<string>& tmp, vector<vector<string>>& result)
    {
    	if(isPalindrome(s))
    	{
    		tmp.push_back(s);
    		result.push_back(tmp);
    		tmp.pop_back();
    		return;
    	}
    	for(int i = 1; i < s.size(); i++)
    	{
    		string str = s.substr(0, i);
    		if(isPalindrome(str))
    		{
    			tmp.push_back(str);
    			helper(s.substr(i, s.size() - i), tmp, result);
    			tmp.pop_back();
    		}
    	}
    	return;
    }

    bool isPalindrome(string s)
    {
    	int start = 0;
    	int end = s.size() - 1;
    	while(start < end)
    	{
    		if(s[start] != s[end])
    		{
    			return false;
    		}
    		start++;
    		end--;
    	}
    	return true;
    }
};

int main(int argc, char const *argv[])
{
	string s = "aaabb";
	vector<vector<string>> result = Solution().partition(s);
	for(auto it : result)
	{
		for(auto itt: it)
		{
			cout << itt << " ";
		}
		cout << endl;
	}
	return 0;
}