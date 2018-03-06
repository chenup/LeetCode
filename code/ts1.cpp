#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> vec;
		int b1, b2;
		auto nums_copy(nums);
		sort(nums.begin(), nums.end());
		vector<int>::iterator it = nums.begin();
		while (it != nums.end())
		{
			int val = target - *it;
			if (binary_search(it + 1, nums.end(), val))
			{
				auto res = upper_bound(it + 1, nums.end(), val);
				b1 = *it;
				b2 = *(res - 1);
				break;
			}
			it++;
		}
		auto b = find(nums_copy.begin(), nums_copy.end(), b1);
		if (b1 == b2)
		{
			b1 = b - nums_copy.begin();
			b2 = find(b + 1, nums_copy.end(), b2) - nums_copy.begin();
		}
		else
		{
			b1 = b - nums_copy.begin();
			b2 = find(nums_copy.begin(), nums_copy.end(), b2) - nums_copy.begin();
		}
		if (b2 < b1)
		{
			vec.push_back(b2);
			vec.push_back(b1);
		}
		else
		{
			vec.push_back(b1);
			vec.push_back(b2);
		}
		return vec;
	}
};
int main()
{
	vector<int> nums = {4, 2, 3, 15};
	int target = 6;
	Solution s = Solution();
	s.twoSum(nums, target);
	int b;
	cin >> b;
	return 0;
}

