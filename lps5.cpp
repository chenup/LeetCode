#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int iSize, i, j, pos, len, max_len, max_flag, flag;
		iSize = s.size();
		max_len = 0;
		max_flag = 0;
		pos = 0;
		for (i = 0; i < iSize; i++)
		{
			if (iSize - i < max_len + max_flag + 1)
			{
				break;
			}
			j = 0;
			len = 0;
			flag = 0;
			while (true)
			{
				j++;
				if (i - j >= 0 && i + j < iSize)
				{
					if (s[i - j] == s[i + j])
					{
						len++;
					}
					else
					{
						break;
					}
				}
				else
				{
					break;
				}
				
			}
			if(max_flag == 1)
			{
				if ( 2 * len + 1 > 2 * max_len + 2)
				{
					max_len = len;
					max_flag = flag;
					pos = i;
				}
			}
			else
			{
				if ( 2 * len + 1 > 2 * max_len + 1)
				{
					max_len = len;
					max_flag = flag;
					pos = i;
				}
			}
			
			j = 0;
			len = 0;
			while (true)
			{
				if (i + 1 == iSize || s[i] != s[i + 1])
				{
					break;
				}
				flag = 1;
				j++;
				if (i - j >= 0 && i + j + 1 < iSize)
				{
					if (s[i - j] == s[i + j + 1])
					{
						len++;
					}
					else
					{
						break;
					}
				}
				else
				{
					break;
				}
			
			}
			if(max_flag == 1)
			{
				if ( 2 * len + 1 + flag > 2 * max_len + 2 * max_flag)
				{
					max_len = len;
					max_flag = flag;
					pos = i;
				}
			}
			else
			{
				if ( 2 * len + 1 + flag > 2 * max_len + 1)
				{
					max_len = len;
					max_flag = flag;
					pos = i;
				}
			}
		}
		return s.substr(pos - max_len, 1 + max_flag + 2 * max_len);

	}
};

int main()
{
	string s;
	string result;
	cin >> s;
	Solution sol = Solution();
	result = sol.longestPalindrome(s);
	cout << result;
	return 0;
}
