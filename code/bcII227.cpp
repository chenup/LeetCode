#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

enum Status {Valid = 0, InValid};

int runStatus = Valid;


class Solution {
public:
    int calculate(string s) {
    	if(s.size() == 0)
    	{
    		runStatus = InValid;
    		return 0;
    	}
    	stack<int> nums;
    	stack<char> op;
    	int n = 0;
    	int opd1;
    	int opd2;
    	int tmpNum;
    	char tmpOp;
        for(auto c : s)
        {
        	if(c == ' ')
        	{
        		continue;
        	}
        	else if('0' <= c && c <= '9')
        	{
        		n = n * 10 + c - '0';
        	}
        	else if(c == '-' || c == '+' || c == '/' || c == '*')
        	{
        		nums.push(n);
        		n = 0;
        		if(op.size() != 0)
        		{
        			tmpOp = op.top();
        			if(tmpOp == '*')
        			{
        				opd1 = nums.top();
	        			nums.pop();
	        			opd2 = nums.top();
	        			nums.pop();
	        			tmpNum = opd2 * opd1;
	        			nums.push(tmpNum);
	        			op.pop();
        			}
        			else if(tmpOp == '/')
        			{
        				opd1 = nums.top();
	        			nums.pop();
	        			opd2 = nums.top();
	        			nums.pop();
	        			tmpNum = opd2 / opd1;
	        			nums.push(tmpNum);
	        			op.pop();
        			}
        			else if(tmpOp == '-')
        			{
        				tmpNum = -1 * nums.top();
        				nums.pop();
	        			nums.push(tmpNum);
	        			op.pop();
	        			op.push('+');
        			}
        		}
        		op.push(c);
        	}
        	else
        	{
        		runStatus = InValid;
        		return 0;
        	}
        }
        nums.push(n);
        while(op.size() > 0)
        {
        	tmpOp = op.top();
        	op.pop();
        	opd1 = nums.top();
        	nums.pop();
        	opd2 = nums.top();
        	nums.pop();
        	if(tmpOp == '+')
        	{
        		tmpNum = opd2 + opd1;
        	}
        	else if(tmpOp == '-')
        	{
        		tmpNum = opd2 - opd1;
        	}
        	else if(tmpOp == '*')
        	{
        		tmpNum = opd2 * opd1;
        	}
        	else if(tmpOp == '/')
        	{
        		tmpNum = opd2 / opd1;
        	}
        	nums.push(tmpNum);
        }
        return nums.top();
    }
};

int main()
{
	string str = "1*2  -3/4+5*6-7*8+9/ 10 ";
	cout << Solution().calculate(str); 
	return 0;
}