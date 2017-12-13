#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
	int lengthOfLastWord(string s) {
        int len = 0;
        int N = s.size();
        int flag = 1;
        for(int i = N - 1; i >= 0; i--)
        {
        	if(s[i] == ' ' && flag == 0)
        	{
        		return len;
        	}
        	else if(s[i] != ' ')
        	{
        		flag = 0;
        		len++;
        	}
        }
        return len;
    }
};

int main()
{
	string s = "Hello World";
	int result = Solution().lengthOfLastWord(s);
	cout << result << endl;
	return 0;
}