class Solution {
public:
    bool isHappy(int n) {
        set<int> tmp;
        while(n != 1)
        {
        	tmp.insert(n);
        	n = helper(n);
        	if(tmp.find(n) != tmp.end())
        	{
        		return false;
        	}
        }
        return true;
    }

    int helper(int n)
    {
    	int sum = 0;
    	while(n)
    	{
    		int tmp = n % 10;
    		n = n / 10;
    		sum += tmp * tmp;
    	}
    	return sum;
    }
};