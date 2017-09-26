#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
		int threeSumClosest(vector<int>& nums, int target)
		{
			int result = 0;
			int min;
			sort(nums.begin(), nums.end());
			vector<int> pos;
			for(int p = 0; p < nums.size(); p++)
			{
				if(p == nums.size() - 1)
				{
					pos.push_back(p);
					break;
				}
				if(nums[p] != nums[p + 1])
				{
					pos.push_back(p);
				}
			}
			int nlen = nums.size();
			int plen = pos.size();
			int i = 0;
			int flag = 0;
			
			while(i < plen)
			{

				if(plen != 1 && i == plen - 1 && pos[i] - pos[i - 1] <= 2)
				{
					break;
				}
				int j;
				result = nums[pos[i]];
				if(i == 0 && pos[i] >= 1)
				{
					j = i;
				}
				else if(i > 0 && pos[i] - pos[i - 1] >= 2)
				{
					j = i;
				}
				else
				{
					j = i + 1;
				}
			
				while(j < plen)
				{
					if(plen != 1 && j == plen - 1 && pos[j] - pos[j - 1] <= 1)
					{
						break;
					}
					int k;
					result += nums[pos[j]];
					if(j == 0 && pos[j] >= 2)
					{
						k = j;
					}
					else if(j > 0 && i == j && pos[j] - pos[j - 1] >= 3)
					{
						k = j;
					}
					else if(j > 0 && i < j && pos[j] - pos[j - 1] >= 2)
					{
						k = j;
					}
					else
					{
						k = j + 1;
					}
					while(k < plen)
					{
						result += nums[pos[k]];
						if(flag == 0)
						{
							flag = 1;
							min = result;
							if(result > target)
							{
								result -= nums[pos[k]];
								break;
							}
						}
						else if(abs(target - min) >= abs(target - result))
						{
							min = result;
							if(result > target)
							{
								result -= nums[pos[k]];
								break;
							}
						}
						result -= nums[pos[k]];
						k++;
					}
					result -= nums[pos[j]];
					j++;
				}
				i++;
			}
			return min;
		} 
};

int main()
{
	vector<int> nums = {6,-18,-20,-7,-15,9,18,10,1,-20,-17,-19,-3,-5,-19,10,6,-11,1,-17,-15,6,17,-18,-3,16,19,-20,-3,-17,-15,-3,12,1,-9,4,1,12,-2,14,4,-4,19,-20,6,0,-19,18,14,1,-15,-5,14,12,-4,0,-10,6,6,-6,20,-8,-6,5,0,3,10,7,-2,17,20,12,19,-13,-1,10,-1,14,0,7,-3,10,14,14,11,0,-4,-15,-8,3,2,-5,9,10,16,-4,-3,-9,-8,-14,10,6,2,-12,-7,-16,-6,10};

	int target = -52;
	int result = Solution().threeSumClosest(nums, target);
	cout << result;
	return 0;
}