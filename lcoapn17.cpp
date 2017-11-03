#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    vector<string> letterCombinations(string digits) {
    	    stirng letter[9] = {" ", "", "abc", "def", "ghi", "jkl", ";"}; 
    }
};

int main()
{
	string digits = "";
	vector<string> result = Solution().letterCombinations(digits);
	for(auto &v: result)
	{
		cout << *v << endl;
	}
	return 0;
}