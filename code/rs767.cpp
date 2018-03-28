class Solution {
public:
    string reorganizeString(string S) {
        map<char, int> tmp;
        int l = S.size();
        string res = "";
        if(S == "")
        {
        	return res;
        }
        if(l == 1)
        {
        	return S;
        }
        int max_n = 1;
        int max_c = S[0];
        for(auto it : S)
        {
        	if(tmp.find(it) != tmp.end())
        	{
        		tmp[it]++;
        		if(tmp[it] > max_n)
        		{
        			max_n = tmp[it];
        			max_c = it;
        		}
        	}
        	else
        	{
        		tmp[it] = 1;
        	}
        }
        if((l % 2 == 1 && max_n <= l / 2 + 1) || (l % 2 == 0 && max_n <= l / 2))
        {	
        	string str(l, '#');
        	int i = 0;
        	while(max_n--)
        	{
        		str[i] = max_c;
        		i += 2;
        	}
        	tmp.erase(max_c);
        	for(auto it : tmp)
        	{
        		while(it.second--)
        		{
        			if(i >= l)
        			{
        				i = 1;
        			}
        			str[i] = it.first;
        			i += 2;
        		}
        	}
        	return str;
        }
        return res;
    }
};