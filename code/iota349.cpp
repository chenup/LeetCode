class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        map<int, int> tmp;
        vector<int> res;
        for(auto it : nums1)
        {
        	if(tmp.find(it) == tmp.end())
        	{
        		tmp[it] = 0;
        	}
        }
        for(auto it : nums2)
        {
        	if(tmp.find(it) != tmp.end())
        	{
        		if(tmp[it]++ == 0)
        		{
        			res.push_back(it);
        		}
        		
        	}
        	
        }
        return res;
    }
};