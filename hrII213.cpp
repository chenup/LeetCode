class Solution {
public:
    int rob(vector<int>& nums) {
        int tmp = 0;
        int max1 = 0;
        int max2 = 0;
        int i;
        if(nums.size() == 0)
        {
            return 0;
        }
        else if(nums.size() == 1)
        {
            return nums[0];
        }
        for(i = 0; i < nums.size() - 1; i++)
        {
            int a = tmp + nums[i];
            int b = max1;
            tmp = b;
            max1 = a > b ? a : b;
        }
        tmp = 0;
        for(i = 1; i < nums.size(); i++)
        {
            int a = tmp + nums[i];
            int b = max2;
            tmp = b;
            max2 = a > b ? a : b;
        }
        return max1 > max2 ? max1 : max2;
    }
};