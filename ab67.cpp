#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int c = 0;
        int i, j; 
        for(i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; i--, j--)
        {
        	int tmp = (a[i] - '0') + (b[j] - '0') + c;
        	c = (tmp & 0x02) >> 1;
        	if(tmp & 0x01)
        	{
        		result = "1" + result;
        	}
        	else
        	{
        		result = "0" + result;
        	}
        }
        while(i >= 0)
        {
        	int tmp = (a[i] - '0') + c;
        	c = (tmp & 0x02) >> 1;
        	if(tmp & 0x01)
        	{
        		result = "1" + result;
        	}
        	else
        	{
        		result = "0" + result;
        	}
        	i--;
        }
        while(j >= 0)
        {
        	int tmp = (b[j] - '0') + c;
        	c = (tmp & 0x02) >> 1;
        	if(tmp & 0x01)
        	{
        		result = "1" + result;
        	}
        	else
        	{
        		result = "0" + result;
        	}
        	j--;
        }
        if(c == 1)
        {
        	result = "1" + result;
        }
        return result;
    }
};

int main()
{
	string a = "";
	string b = "11111111111111";
	string result = Solution().addBinary(a, b);
	cout << result << endl;
	return 0;
}