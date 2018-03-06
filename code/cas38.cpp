#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
	string countAndSay(int n) {
    	int count = 1;
    	string s = "1";
    	for(int i = 1; i < n; i++)
    	{
    		count = 1;
    		string tmp = "";
    		for(int j = 1; j < s.size(); j++)
    		{
    			if(s[j] == s[j - 1])
    			{
    				count++;
    			}
    			else
    			{
    				tmp = tmp + (char)(count + '0') + s[j - 1];
    				count = 1;
    			}
    		}
    		s = tmp + (char)(count + '0') + s[s.size() - 1];
    	}
    	return s;
    }
};

int main()
{
	int n = 4;
	string result = Solution().countAndSay(n);
	cout << result << endl;
	return 0;
}