class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> tmp;
        int times = nums.size() / 2;
        for(auto it : nums)
        {
        	if(tmp.find(it) != tmp.end())
        	{
        		tmp[it]++;
        	}
        	else
        	{
        		tmp[it] = 1;
        	}
        	if(tmp[it] > times)
        	{
        		return it;
        	}
        } 
    }
};