class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
    	vector<int> res;
    	int n = 0, m = 0;
    	int cm = 0;
    	int cn = 0;
    	for(auto it : nums)
    	{
    		if(it == n)
    		{
    			cn++;
    		}
    		else if(it == m)
    		{
    			cm++;
    		}
    		else if(cm == 0)
    		{
    			m = a;
    			cm = 1;
    		}
    		else if(cn == 0)
    		{
    			n = a;
    			cn = 1;
    		}
    		else
    		{
    			cm--;
    			cn--;
    		}
    	}
    	cm = 0;
    	cn = 0;
    	for(auto it : nums)
    	{
    		if(it == m)
    		{
    			cm++;
    		}
    		else if(it == n)
    		{
    			cn++;
    		}
    	}
    	if(m > nums.size() / 3)
    	{
    		res.push_back(m);
    	}
    	if(n > nums.size() / 3)
    	{
    		res.push_back(n);
    	}
    	return res;    
    }
}; 