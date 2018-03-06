class Solution {
public:
    bool isIsomorphic(string s, string t) {
       	unordered_map<char, char> tmp;
       	set<char> visited;;
       	int s_l = s.size();
       	int t_l = t.size();
       	if(s_l != t_l)
       	{
       		return false;
       	}
       	for(int i = 0; i < s_l; i++)
       	{
       		if(tmp.find(s[i]) != tmp.end())
       		{
       			if(tmp[s[i]] != t[i])
       			{
       				return false;
       			}
       		}
       		else
       		{
       			if(visited.find(t[i]) != visited.end())
       			{
       				return false;
       			}
       			tmp[s[i]] = t[i];
       			visited.insert(t[i]);
       		}
       	}
       	return true;
    }
};