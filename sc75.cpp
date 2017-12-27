#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int count = 0;
        while(count < nums.size())
        {
        	auto it = nums.begin() + i;
        	if(*it == 1)
        	{
        		i++;
        	}
        	else if(*it == 0)
        	{
        		nums.erase(it);
        		nums.insert(nums.begin(), 0);
        		i++;
        	}
        	else if(*it == 2)
        	{
        		nums.erase(it);
        		nums.insert(nums.end(), 2);
        	}
			count++;
        }
    }
};

int main()
{
	vector<int> nums = {0, 0, 1, 2, 1, 2, 0, 1};
	Solution().sortColors(nums);
	for(auto it : nums)
	{
		cout << it << endl;
	}
	return 0;
}