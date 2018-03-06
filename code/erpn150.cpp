#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> num_stack;
        for(auto it : tokens)
        {
        	char c = it[0];
        	if(c == '-' && it.size() > 1)
        	{
        		int n = 0;
        		for(int i = 1; i < it.size(); i++)
        		{
        			n = n * 10 + it[i] - 48;
        		}
        		num_stack.push_back(-1 * n);
        	}
        	else if('0' <= c && c <= '9')
        	{
        		int n = 0;
        		for(int i = 0; i < it.size(); i++)
        		{
        			n = n * 10 + it[i] - 48;
        		}
        		num_stack.push_back(n);
        	}
        	else
        	{
        		int a = num_stack[num_stack.size() - 1];
        		num_stack.pop_back();
        		int b = num_stack[num_stack.size() - 1];
        		num_stack.pop_back();
        		int res;
        		switch(c)
        		{
        			case '+':
        			{
        				res = b + a;
        			}
        			break;
        			case '-':
        			{
        				res = b - a;
        			}
        			break;
        			case '*':
        			{
        				res = b * a;
        			}
        			break;
        			case '/':
        			{
        				res = b / a;
        			}
        			break;
        			default:
        			break;
        		}
        		num_stack.push_back(res);
        	}
        }
        return num_stack[0];
    }
};

int main(int argc, char const *argv[])
{
	vector<string> tokens = {"2", "1", "+", "3", "*"};
	int res = Solution().evalRPN(tokens);
	cout << res << endl;
	return 0;
}