#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
    	   	vector<char> tmp;
    	   	dtol(tmp, 0, digits);
    	 	return result;
    }

    void dtol(vector<char> &tmp, int d, string &digits)
    {
    	int n = digits.size();
    	if(d >= n)
    	{
    	
			if(tmp.size() != 0)
			{
				string str = "";
	    		for(int i = 0; i < tmp.size(); i++)
	    		{
	    			str += tmp[i];
				}
				result.push_back(str);
			}
    		
    		return;
    	}
    	string w = letter[digits[d] - '0'];
    	for(int i = 0; i < w.size(); i++)
    	{
    		tmp.push_back(w[i]); 
    		dtol(tmp, d + 1, digits);
    		tmp.pop_back();
    	}
    }

    Solution()
    {
		letter = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};     	
    }
private:
	vector<string> result;
	vector<string> letter;
};

int main()
{
	string digits = "";
	vector<string> result = Solution().letterCombinations(digits);
	for(auto v: result)
	{
		cout << v << endl;
	}
	return 0;
}