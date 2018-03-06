class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0)
        {
        	return 0;
        }
        int min = 0;
        int sum = 0;
        auto start = nums.begin();
        auto end = nums.begin();
        sum += *end;
        while(true)
        {
        	if(sum >= s)
        	{
        		int tmp = end - start + 1;
        		if(tmp == 1)
        		{
        			return 1;
        		}
        		else if(min == 0)
        		{
        			min = tmp;
        		}
        		else if(tmp < min)
        		{
        			min = tmp;
        		}
        		sum -= *start;
        		start++;
        	}
        	else
        	{
        		end++;
        		if(end >= nums.end())
        		{
        			break;
        		}
        		else
        		{
        			sum += *end;
        		}
        	}
        }
        return min;
    }
};