class Solution {
public:
	Solution()
	{
		vector<char> level1 = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
		vector<char> level2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
		vector<char> level3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
		for(auto it : level1)
		{
			ch[it - 'a'] = 1;
		}
		for(auto it : level2)
		{
			ch[it - 'a'] = 2;
		}
		for(auto it : level3)
		{
			ch[it - 'a'] = 3;
		}
	}

    vector<string> findWords(vector<string>& words) 
    {
    	vector<string> res;
    	int tmp;
    	int t;
        for(auto str : words)
        {
        	if(str == "")
        	{
        		res.push_back(str);
        		continue;
        	}
        	if('a' <= str[0] && str[0] <= 'z')
        	{
        		tmp = ch[str[0] - 'a'];
        	}
        	if('A' <= str[0] && str[0] <= 'Z')
        	{
        		tmp = ch[str[0] - 'A'];
        	}
        	for(auto c : str)
        	{
        		if('a' <= c && c <= 'z')
	        	{
	        		t = ch[c - 'a'];
	        	}
	        	if('A' <= c && c <= 'Z')
	        	{
	        		t = ch[c - 'A'];
	        	}
        		if(t != tmp)
        		{
        			break;
        		}
        	}
        	if(t == tmp)
        	{
        		res.push_back(str);
        	}
        }
        return res;
    }
private:
	int ch[26];
};