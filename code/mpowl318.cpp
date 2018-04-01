class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> tmp(n, 0);
        for(int i = 0; i < words.size(); i++)
        {
        	for(auto it : words[i])
        	{
        		tmp[i] |= 1 << (it - 'a');
        	}
        }
        int max = 0; 
        for(int i = 0; i < tmp.size(); i++)
        {
        	for(int j = i + 1; j < tmp.size(); j++)
        	{
        		if(!(tmp[i] & tmp[j]))
        		{
        			int l = words[i].size() * words[j].size();
        			if(l > max)
        			{
        				max = l;
        			}
        		}
        	}
        }
        return max;
    }
};