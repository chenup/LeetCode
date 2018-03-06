#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
	public:
    int removeElement(vector<int>& nums, int val) {
     	int sum = 0;
     	auto it = nums.begin();
     	while(it != nums.end())
     	{
     		if(*it != val)
     		{
     			sum++;
     			it++;
     		}
     		else
     		{
     			it = nums.erase(it);
     		}
     	}
     	return sum;   
    }
};

int main()
{
	vector<int> nums = {1,1,2,3,3};
	int val = 2;
	int result = Solution().removeElement(nums, val);
	cout << result << endl;
	for(auto it : nums)
	{
		cout << it << endl;
	}
	return 0;
}