#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())
        {
        	return true;
        }
        int p = 0;
        int e = s.size() - 1;
        while(p < e)
        {
        	while(true)
        	{
        		if(p >= s.size() || ('0' <= s[p] && s[p] <= '9') || ('a' <= s[p] && s[p] <= 'z') || ('A' <= s[p] && s[p] <= 'Z'))
        		{
        			if(p < s.size() && ('A' <= s[p] && s[p] <= 'Z'))
        			{
        				s[p] = s[p] + 32;
					}
        			break;
        		}
        		else
        		{
        			p++;
        		}
        	}
        	while(true)
        	{
        		if(e < 0 || ('0' <= s[e] && s[e] <= '9') || ('a' <= s[e] && s[e] <= 'z') || ('A' <= s[e] && s[e] <= 'Z'))
        		{
        			if(e >= 0 && ('A' <= s[e] && s[e] <= 'Z'))
        			{
        				s[e] = s[e] + 32;
					}
        			break;
        		}
        		else
        		{
        			e--;
        		}
        	}
        	if(s[p] == s[e])
        	{
        		p++;
        		e--;
        	}
        	else
        	{
        		return false;
        	}
        }
        return true;
    }
};

int main()
{
	string s = "0P";
	bool result = Solution().isPalindrome(s);
	cout << result << endl;
	return 0;
}