class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> tmp;
        for(int i = 0; i < s.size(); i++)
        {
        	if(tmp.find(s[i]) == tmp.end())
        	{
        		tmp[s[i]] = i;
        	}
        	else if(tmp[s[i]] >= 0)
        	{
        		tmp[s[i]] = -1;
        	}
        }
        int min = INT_MAX;
        for(auto it : tmp)
        {
        	if(tmp[it] >= 0)
        	{
        		if(min > tmp[it])
        		{
        			min = tmp[it];
        		}
        	}
        }
        return min == INT_MAX ? -1 : min;
    }
};