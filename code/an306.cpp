class Solution {
public:
    bool isAdditiveNumber(string num) {
        if(num.size() <= 2)
        {
        	return false;
        } 
        for(int i = 0; i < num.size() / 2; i++)
        {
        	for(int j = i + 1; j < num.size() - 1; j++)
        	{ 
        		if(num[0] == '0' && i > 0)
        		{
        			return false;
        		}
        		if(num[i + 1] == '0' && j > i + 1)
        		{
        			break;
        		}
        		if(num.size() - j - 1 < max(i + 1, j - i))
        		{
        			break;
        		}
        		if(helper(num.substr(0, i + 1), num.substr(i + 1, j - i), num.substr(j + 1, num.size() - j)))
        		{
        			return true;
        		}
        	}
        }
        return false;
    }
    bool helper(string a, string b, string str)
    {
    	if(str.size() == 0)
    	{
    		return true;
    	}
    	long long inta;
    	long long intb;
    	stringstream stream;
        stream.clear();
    	stream << a;
    	stream >> inta;
        stream.clear();
    	stream << b;
    	stream >> intb;
    	long long sum = inta + intb;
    	string sumstr = to_string(sum);
    	if(str.size() < sumstr.size())
    	{
    		return false;
    	}
    	for(int i = 0; i < sumstr.size(); i++)
    	{
    		if(str[i] != sumstr[i])
    		{
    			return false;
    		}
    	}
    	return helper(b, sumstr, str.substr(sumstr.size(), str.size() - sumstr.size()));
    }
};