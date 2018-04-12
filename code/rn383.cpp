class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int a[26] = {0};
        for(auto c : magazine)
        {
        	a[c - 'a']++;
        }
        for(auto c : ransomNote)
        {
        	if(--a[c - 'a'] < 0)
        	{
        		return false;
        	}
        }
        return true;
    }
};