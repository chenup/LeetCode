class Solution {
public:
    string getHint(string secret, string guess) {
        if(secret == "")
        {
        	return string("0A0B");
        }
        int bulls = 0;
        int cows = 0;
        int record[26] = {0};
        for(int i = 0; i < secret.size(); i++)
        {
        	if(secret[i] == guess[i])
        	{
        		bulls++;
        	}
        	else
        	{
        		if(record[secret[i] - 'a']++ < 0)
        		{
        			cows++;
        		}
        		if(record[guess[i] - 'a']-- > 0)
        		{
        			cows++;
        		}
        }
        string res = "";
        res = to_string(bulls) + "A" + to_string(cows) + "B";
        return res;
    }
};