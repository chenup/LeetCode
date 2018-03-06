#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int>& nums) { 
		int N = nums.size();
		if(N == 0)
		{
			return;	
		} 
    	int max = nums[N - 1];
    	int i;
    	int tmp;
    	for(i = N - 1; i >= 0; i--)
    	{
    		if(nums[i] >= max)
    		{
    			max = nums[i];
    		}
    		else
    		{
    			break;
   			}
    	}
    	if(i < 0)
    	{
    		for(int j = 0; j < N / 2; j++)
    		{
    			tmp = nums[j];
    			nums[j] = nums[N - j - 1];
    			nums[N - j - 1] = tmp;
    		}
    	}
    	else
    	{
    		int m = (N - i - 1) / 2;
    		for(int j = i + 1; j <= m + i; j++)
    		{
    			tmp = nums[j];
    			nums[j] = nums[N - j + i];
    			nums[N - j + i] = tmp;
    		}
    		for(int j = i + 1; j < N; j++)
    		{
    			if(nums[i] < nums[j])
    			{
    				tmp = nums[i];
    				nums[i] = nums[j];
    				nums[j] = tmp;
    				break;
    			}
    		}
    	}
    }
};

int main()
{
	vector<int> nums = {5, 4 ,3 , 2 ,1};
	Solution().nextPermutation(nums);
	for(auto it = nums.begin(); it != nums.end(); it++)
	{
		cout << *it << endl;
	}
	return 0;
}