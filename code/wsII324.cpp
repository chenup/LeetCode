class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mid = nums[n / 2];
        vector<int> res(n, mid);
        int lo = 1;
        int hi = (n % 2 == 1 ? n - 1 : n - 2);
        for(int i = n - 1; nums[i] > mid; i--)
        {
        	res[lo] = nums[i];
        	lo += 2;
        }
        for(int i = 0; nums[i] < mid; i++)
        {
        	res[hi] = nums[i];
        	hi -= 2;
        }
        nums = res;
    }
};