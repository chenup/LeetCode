#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int count = 0;
        int result = 0;
    	int max = 0;
    	vector<int> tmp;
        for(int i = 0; i < s.size(); i++)
        {
        	if(s[i] == '(')
        	{
        		count++;
        	}
        	else if(s[i] == ')' && count != 0)
        	{
        		count--;
        		tmp.push_back(i);
        	}
        }
        int num1 = 0;
        int num2 = 0;
        for(auto it = tmp.end() - 1; it >= tmp.begin();it--)
        {
        	cout << *it;
        	if(it == tmp.begin())
        	{
        		result = result + num2 + num1 + 1;
    			if(result > max)
    			{
    				max = result;
    			}
    			result = 0;
    			num1 = 0;
    			num2 = 0;
    			break;
        	}
        	int a = *it - *(it - 1);
        	if(a == 1)
        	{
        		num1++;
        	}
        	else if(a == 2)
        	{
        		num2++;
        	}
        	else
        	{
        		if(num1 >= a - 2)
        		{
        			result += a - 2;
        			num1 -= a - 2;
        		}
        		else
        		{
        			result = result + num2 + num1 + 1;
        			if(result > max)
        			{
        				max = result;
        			}
        			result = 0;
        			num1 = 0;
        			num2 = 0;
        		}
        	}
        }
        return 2 * max;
    }
};

int main()
{
	string s = ")()())";
	int result = Solution().longestValidParentheses(s);
	cout << result << endl;
	return 0;
}