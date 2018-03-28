class Solution {
public:
    int numJewelsInStones(string J, string S) {
        bool ah[26] = {false};
        bool Ah[26] = {false};
        int sum = 0;
        for(auto it : J)
        {
        	if('a' <= it && it <= 'z')
        	{
        		ah[it - 'a'] = true;
        	}
        	else
        	{
        		Ah[it - 'A'] = true;
        	}
        }
        for(auto s : S)
        {
        	if('a' <= s && s <= 'z')
        	{
        		if(ah[s - 'a'])
        		{
        			sum++;
        		}
        		
        	}
        	else if(Ah[s - 'A'])
        	{
        		sum++;
        	}
        }
        return sum;
    }
};