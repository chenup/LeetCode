#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> tmp;
        string str = "";
        for(int i = 0 ; i < path.size(); i++)
        {
        	if(path[i] == '/')
        	{
        		if(str == '..')
        		{
        			if(!tmp.empty())
        			{
        				tmp.pop_back();
        			}
        		}
        		else if(str == ".")
        		{
        			;
        		}
        		else
        		{
        			tmp.push_back(str);
        		}
        		str = "";
        	}
        	else
        	{
        		str += path[i];
        	}
        }
        string result = "";
        for(auto it : tmp)
        {
        	result += "/";
        	result += it;
        }
        return result;
    }
};

int main()
{
	string path = "/a/./b/../../c/";
	string result = Solution().simplifyPath(path);
	cout << result << endl;
	return 0;
}