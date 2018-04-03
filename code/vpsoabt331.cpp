class Solution {
public:
    bool isValidSerialization(string preorder) 
    {
    	istringstream in(preorder);
    	string t;
    	int degree = 1;
    	bool flag = false;
    	while(getline(in, t, ','))
    	{
    		if(flag)
    		{
    			return false;
    		}
    		if(t == "#" && --degree == 0)
    		{
    			flag = true;
    		}
    		else if(t != "#")
    		{
    			degree++;
    		}
    	}
    	return degree == 0;
    }
};