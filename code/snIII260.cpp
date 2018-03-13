enum Status{Valid = 0, InValid};

int runStatus = Valid;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        if(nums.size() < 2)
        {
        	runStatus = InValid;
        	return res;
        }
        res = vector<int>(2, 0);
        int tmp = 0;
        for(auto it : nums)
        {
        	tmp = tmp ^ it;
        }
        int sep = tmp & (-1 * tmp);
        for(auto it : nums)
        {
        	if(sep & it)
        	{
        		res[0] ^= it;
        	}
        	else
        	{
        		res[1] ^= it;
        	}
        }
        return res;
    }
};