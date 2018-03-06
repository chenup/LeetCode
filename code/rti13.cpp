#include <iostream>
#include <algorithm>
#include <map>

using namespace std; 
class Solution {
public:
    int romanToInt(string s) {
    	map<string, int> table = {{"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40}, {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}};
        int result = 0;
        int i = 0;
        while(i < s.size())
        {
        	string tmp = "";
        	if(i == s.size() - 1)
        	{
        		tmp += s[i];
        		result += table[tmp];
        		i++;
        	}
        	else
        	{
        		tmp += s[i];
        		tmp += s[i+1];
        		auto it = table.find(tmp);
        		if(it == table.end())
        		{	
        			string str = "";
        			str += s[i];
        			result += table[str];
        			i++;
        		}
        		else
        		{
        			result += table[tmp];
        			i += 2;
        		}
        	}
        }
        return result;
    }
};
int main()
{
	string s = "CDXXXIV";
	int result = Solution().romanToInt(s);
	cout << result << endl;
	return 0;
}
