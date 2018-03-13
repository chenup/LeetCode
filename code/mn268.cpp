class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
        {
        	return -1;
        }
        int res = (n + 1) * n / 2;
        for(auto it : nums)
        {
        	res -= it;
        }
        return res;
    }
};