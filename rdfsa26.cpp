#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int>& nums) {
        int result = 0;
        int tmp;
        auto it = nums.begin();
        while(it != nums.end())
        {
            if(it - nums.begin() == 0)
            {
            	result += 1;
            	tmp = *it;
            }
            else if(*it != tmp)
            {
            	result += 1;
            	tmp = *it;
            }
            else
            {
            	it = nums.erase(it);
            	continue;
            }
            it = it + 1;
        }
        return result;
    }
};

int main()
{
	vector<int> nums = {1,1,2,3,3,4,4};
	int result = Solution().removeDuplicates(nums);
	cout << result << endl;
	return 0;
}