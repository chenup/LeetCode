class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> table;
        int i = 0;
        int count = 0;
        for(auto c : pattern)
        {
            count++;
        	string tmp = "";
        	while(i < str.size() && str[i] != ' ')
        	{
        		tmp += str[i];
        		i++;
        	}
        	if(table.find(c) != table.end() && table[c] != tmp)
        	{
        		return false;
        	}
        	else if(table.find(c) == table.end())
        	{
                for(auto it : table)
                {
                    if(it.second == tmp)
                    {
                        return false;
                    }
                }
        		table[c] = tmp;
        	}
        	i++;
            if(i >= str.size())
            {
                break;
            }
        }
        if(count != pattern.size() || i < str.size())
        {
            return false;
        }
        return true;
    }
};