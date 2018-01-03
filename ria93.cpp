#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<int> tmp;
        int n = s.size();
        computeIp(result, tmp, s, 0, n, 1);
        return result;
    }

    void computeIp(vector<string>& result, vector<int> tmp, string s, int i, int n, int d)
    {
    	if(d == 4)
    	{
    		int num = n - i - 1;
    		if(num <= 2 && num >= 0)
    		{
    			int c;
    			if(num != 0 && s[i] == '0')
    			{
    				return;
				}
				switch(num)
				{
					case 0:
					{
						c = s[i] - '0';
					}
					break;
					case 1:
					{
						c = (s[i] - '0') * 10 + (s[i + 1] - '0'); 
					}
					break;
					case 2:
					{
						c = (s[i] - '0') * 100 + (s[i + 1] - '0') * 10 + (s[i + 2] - '0'); 
					}
					break;
					default:
					break; 
				}
				if(c >= 0 && c <= 255)
				{
					tmp.push_back(c);
				}
				else
				{
					return;
				}
				string str = to_string(tmp[0]) + "." + to_string(tmp[1]) + "." + to_string(tmp[2]) + "." + to_string(tmp[3]);
				result.push_back(str);
				tmp.pop_back();
				return;
    		}
    		else
    		{
    			return;
    		}
    	}
    	else
    	{
    		int k;
    		for(k = i; k <= i + 2; k++)
    		{
    			if(k < n)
    			{
    				int c;
    				if(k - i != 0 && s[i] == '0')
    				{
    					return;
					}
    				switch(k - i)
    				{
    					case 0:
    					{
    						c = s[i] - '0';
    					}
    					break;
    					case 1:
    					{
    						c = (s[i] - '0') * 10 + (s[i + 1] - '0'); 
    					}
    					break;
    					case 2:
    					{
    						c = (s[i] - '0') * 100 + (s[i + 1] - '0') * 10 + (s[i + 2] - '0'); 
    					}
    					break;
    					default:
    					break;
    				}
    				if(c >= 0 && c <= 255)
    				{
    					tmp.push_back(c);
    				}
    				else
    				{
    					return;
    				}
    				//cout << c << " " << d << endl;
    				computeIp(result, tmp, s, k + 1, n, d + 1);
    				tmp.pop_back();
    			}
    			else
    			{
    				return;
    			}
    		}
    	}
    }
};

int main()
{
	string s = "25525511135";
	vector<string> result = Solution().restoreIpAddresses(s);
	for(auto v : result)
	{
		cout << v << endl;
	}
	return 0;
}