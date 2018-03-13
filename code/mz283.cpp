/*
class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
    	if(nums.size() == 0)
    	{
    		return;
    	}
    	vector<int>::iterator s = nums.begin();
    	vector<int>::iterator e = nums.begin();
        while(s < nums.end())
        {
        	while(*e == 0)
    		{
    			e++;
    			if(e == nums.end())
    			{
    				return;
    			}
    		}
    	//	cout << "e" << *e << endl;
    		if(*s == 0)
    		{
    			*s = *e;
    			*e = 0;
    		}
            s++;
            if(s > e)
            {
                e = s;
            }

        }
        return;
    }
};
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i = 0, j = 0; i < nums.size(); i++)
        {
        	if(nums[i] != 0)
        	{
        		int tmp = nums[i];
        		nums[i] = nums[j];
        		nums[j] = tmp;
        		j++;
        	}
        }
    }
};