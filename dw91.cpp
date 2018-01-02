#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int a;
        int b;
        int c;
        int n = s.size();
        if(n == 0)
        {
        	return 0;
        }
        else if(s[0] == '0')
        {
        	return 0;
        }
        else
        {
        	b = 1;
        }
        a = 1;
        for(int i = 1; i < n; i++)
        {
        	c = b * judge1(s, i) + a * judge2(s, i);
        	a = b;
        	b = c;
        }
        return c;
    }

    int judge1(string s, int k)
    {
    	if(s[k] == '0')
    	{
    		return 0;
    	}
    	else
    	{
    		return 1;
    	}
    }

    int judge2(string s, int k)
    {
    	int tmp = (s[k - 1] - '0') * 10 + (s[k] - '0');
    	if(tmp >= 10 && tmp <= 26)
    	{
    		return 1;
    	}
    	else
    	{
    		return 0;
    	}
    }
};

int main()
{
	string s = "120";
	int result = Solution().numDecodings(s);
	cout << result << endl;
	return 0;
}#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int a;
        int b;
        int c;
        int n = s.size();
        if(n == 0)
        {
        	return 0;
        }
        else if(s[0] == '0')
        {
        	return 0;
        }
        else
        {
        	b = 1;
        }
        a = 1;
        for(int i = 1; i < n; i++)
        {
        	c = b * judge1(s, i) + a * judge2(s, i);
        	a = b;
        	b = c;
        }
        return c;
    }

    int judge1(string s, int k)
    {
    	if(s[k] == '0')
    	{
    		return 0;
    	}
    	else
    	{
    		return 1;
    	}
    }

    int judge2(string s, int k)
    {
    	int tmp = (s[k - 1] - '0') * 10 + (s[k] - '0');
    	if(tmp >= 10 && tmp <= 26)
    	{
    		return 1;
    	}
    	else
    	{
    		return 0;
    	}
    }
};

int main()
{
	string s = "120";
	int result = Solution().numDecodings(s);
	cout << result << endl;
	return 0;
}