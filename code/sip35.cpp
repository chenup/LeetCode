#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
	int searchInsert(vector<int>& nums, int target) {
        int pos = 0;
        for(auto it = nums.begin(); it != nums.end(); it++)
        {
        	if(target <= *it)
        	{
        		return pos;
        	}
        	else
        	{
        		pos += 1;
        	}
        }
        return pos;
    }
};

int main()
{
	vector<int> nums = {1,2,3,4};
	int target = 4;
	int result = Solution().searchInsert(nums, target);
	cout << result << endl;
	return 0;
}