#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int ssize = s.size();
        string result;
        int i,j;
        int interval;
        int count = 0;
        int total = 2 * (numRows - 1);
        for(i = 0; i < numRows; i++)
        {
        	if(i == 0 || i == numRows - 1)
        	{
        		interval = total;
        		j = i;
        		while(j < ssize)
        		{
        			result[count++] = s[j];
        			j += interval; 
        		}
        	}
        	else
        	{
        		interval = total - 2 * i;
        		j = i;
        		while(j < ssize)
        		{
        			result[count++] = s[j];
        			j += interval;
        			interval = total - interval; 
        		}
        	}
        	
        }
        return result;
    }
};

int main()
{
	string input;
	string result;
	int num;
	cin >> input >> num;
	result = Solution().convert(input, num);
	cout << result;
	return 0;
}