class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    	unordered_set<int> tmp;
    	for(auto it : nums)
    	{
    		if(tmp.find(it) != it.end())
    		{
    			return true;
    		}
    		tmp.insert(it);
    	}
    	return false;
    }
};