class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    	bool flag = true;
    	for(auto it = nums.begin(); it < nums.end() - 1; it++)
    	{
    		if(*it > *(it + 1))
    		{
    			return it - nums.begin();
    		}
    	}
    	return nums.size() - 1;
    }
};