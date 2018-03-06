#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
    	vector<int> tmp;
    	if(num1.size() == 1 && num1[0] == '0')
    	{
    		return "0";
    	}
    	if(num2.size() == 1 && num2[0] == '0')
    	{
    		return "0";
    	}
    	for(int i = num2.size() - 1; i >= 0; i--)
    	{
    		int c = 0;
    		int a = num2[i] - '0';
    		int l = num2.size() - i - 1;
    		if(a == 0)
    		{
    			if(tmp.size() < (l + 1))
    			{
    				tmp.push_back(0);
				}
    			continue;
    		}
    		for(int j = num1.size() - 1; j >= 0; j--)
    		{
    			int b = num1[j] - '0';
    			int idx = num1.size() - j + l;
    			int n = a * b + c; 
    			if(tmp.size() < idx)
    			{
    				c = n / 10;
    				tmp.push_back(n % 10);
    			}
    			else
    			{
    				n += tmp[idx - 1];
    				c = n / 10;
    				tmp[idx - 1] = n % 10;
    			}
    			
    		}
    		if(c != 0)
    		{
    			tmp.push_back(c);
    		}
    	}
    	string str = "";
    	for(auto it = tmp.begin(); it != tmp.end(); it++)
    	{
    		char ch = *it + '0';
    		str = ch + str;
    	}
    	return str;
    }
};

int main()
{
	string num1 = "501";
	string num2 = "6";
	string result = Solution().multiply(num1, num2);
	cout << result << endl;
	return 0;
}