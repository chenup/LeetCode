#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
       int min = nums[0];
       for(auto it = nums.begin(); it < nums.end() - 1; it++)
       {
       		if(*it > *(it + 1))
       		{
       			if(*(it + 1) < min)
       			{
       				min = *(it + 1);
       				return min;
       			}
       			else
       			{
       				break;
       			}
       		}
       }
       return min;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> nums = {4, 5, 6, 0, 1, 2, 3};
	int min = Solution().findMin(nums);
	cout << min << endl;
	return 0;
}