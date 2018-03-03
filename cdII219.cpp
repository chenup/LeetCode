enum Status {Valid = 0, InValid};

int status = Valid;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k <= 0)
        {
        	status = InValid;
        	return false;
        }
        if(nums.size() == 0)
        {
        	return false;
        }
        unordered_map<int, int> indexMap;
        int index = 0;
        for(auto val : nums)
        {
        	if(indexMap.find(val) != indexMap.end())
        	{
        		if(index - indexMap[val] <= k)
        		{
        			return true;
        		}
        		else
        		{
        			indexMap[val] = index;
        		}
        	}
        	else
        	{
        		indexMap[val] = index;
        	}
        	index++;
        }
    	return false;
    }
};