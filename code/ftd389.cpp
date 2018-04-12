class Solution {
public:
    char findTheDifference(string s, string t) {
    	int a[26] = {0};
        for(auto c : s)
        {
        	a[c - 'a']++;
        }
        for(auto c : t)
        {
        	if(--a[c - 'a'] < 0)
        	{
        		return c;
        	}
        }
    }
};