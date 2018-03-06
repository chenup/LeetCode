#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp;
        tmp.insert(tmp.end(), n, -1);
        for(int j = 0; j < n; j++)
        {
        	int i = j;
        	while(i < n)
	        {
	        	if(tmp[i] == -1)
	        	{
	        		tmp[i] = i + nums[i];
	        		if(i > 0 && tmp[i] < tmp[i - 1] )
	        		{	
	        			tmp[i] = tmp[i - 1];
					}
	        		i = tmp[i];
	        		
	        		if(i >= n - 1)
	        		{
	        			return true;
	        		}
	        		continue;
	        	}
	        	else
	        	{
	        		if(tmp[i] < tmp[i - 1])
	        		{
	        			tmp[i] = tmp[i - 1];
					}
				}
	        	break;
	        	
	        }
	   // cout << tmp[j] << endl;
	    if(j + 1 > tmp[j])
		{
			return false;	
		} 
        }
        return false;
    }
};

int main()
{
	vector<int> nums = {5,9,3,2,1,0,2,3,3,1,0,0};
	bool result = Solution().canJump(nums);
	cout << result << endl;
	return 0;
}