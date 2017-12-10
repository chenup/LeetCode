#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s) 
    {
        stack<char> cs;
        int i = 0;
        while(i < s.size())
        {
        	char c = s[i];
        	if(c == '}' || c == ']' || c == ')')
        	{
        		char cc;
        		if(cs.empty())
        		{
        			return false;
        		}
        		else
        		{
        			cc = cs.top();
        		}
        		if((cc == '{' && c == '}') || (cc == '[' && c == ']') || (cc == '(' && c == ')'))
        		{
        			i++;
        			cs.pop();
        		}
        		else
        		{
        			return false;
        		}

        	}
        	else
        	{
        		cs.push(c);
        		i++;
        	}
        }
        if(cs.empty())
        {
        	return true;
        }
        else
        {
        	return false;
        }
    }
};

int main()
{
	string str = "[]{}";

	bool result = Solution().isValid(str);
	cout << result;
	return 0;
}