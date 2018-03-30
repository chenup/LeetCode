class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0;
        int res = 0;
        for(int i = 31; i >= 0; i--)
        {
        	mask |= (1 << i);
        	set<int> s;
        	for(auto n : nums)
        	{
        		s.insert(n & mask);
        	}
        	int t = res | (1 << i);
        	for(auto prefix : s)
        	{
        		if(s.count(t ^ prefix))
        		{
        			res = t;
        			break;
        		}
        	}
        }
        return res;
    }
};