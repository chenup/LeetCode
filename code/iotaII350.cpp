class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> tmp;
        vector<int> res;
        for(auto a : nums1)
        {
        	tmp[a]++;
        }
        for(auto a : nums2)
        {
        	if(tmp[a]-- > 0)
        	{
        		res.push_back(a);
        	}
        }
        return res;
    }
};