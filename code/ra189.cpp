#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int l = n - k;
        int r = k;
        if(l < r)
        {
        	for(int i = 0; i < l; i++)
	        {
	        	int tmp = nums[0];
	        	nums.erase(nums.begin());
	        	nums.push_back(tmp);
	        }
        }
        else
        {
        	for(int i = 0; i < r; i++)
	        {
	        	int tmp = nums[nums.size() - 1];
	        	nums.insert(nums.begin(), tmp);
	        	nums.pop_back();
	        }
        }
    }
};

int main()
{
	vector<int> nums = {1,2,3,4,5,6,7};
	int k = 2;
	Solution().rotate(nums, k);
	for(auto it : nums)
	{
		cout << it << endl;
	}
	return 0;
}