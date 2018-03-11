class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> tmp;
        for(auto it : s)
        {
        	if(tmp.find(it) != tmp.end())
        	{
        		tmp[it]++;
        	}
        	else
        	{
        		tmp[it] = 1;
        	}
        }
        for(auto it : t)
        {
        	if(tmp.find(it) != tmp.end())
        	{
        		tmp[it]--;
        		if(tmp[it] == 0)
        		{
        			tmp.erase(it);
        		}
        	}
        	else
        	{
        		return false;
        	}
        }
        if(tmp.size())
        {
        	return false;
        }
        return true;
    }
};