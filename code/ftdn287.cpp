enum Status{Valid = 0, InValid};

int runStatus = Valid;

/*
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
        {
        	runStatus = InValid;
        	return 0;
        }
        int ln;
        int lo = 1;
        int hi = n;
        int mid;
        while(lo < hi)
        {
        	mid = lo + (hi - lo) / 2;
        	 ln = 0;
        	for(auto it : nums)
        	{
        		if(it <= mid)
	        	{
	        		ln++;
	        	}
        	}
        	if(ln <= mid)
        	{
        		lo = mid + 1;
        	}
        	else
        	{
        		hi = mid;
        	}
        }
        return lo;
    }
};
*/
class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {
    	int n = nums.size();
        if(n <= 1)
        {
        	runStatus = InValid;
        	return 0;
        }
        int slow = nums[slow]
        int fast = nums[nums[fast]];
        int t = 0;
        if(fast == slow)
        {
        	slow = nums[slow]
        	fast = nums[nums[fast]];
        }
        while(true)
        {
        	slow = nums[slow];
        	t = nums[t];
        	if(slow == t) break;
        }
        return slow;
    }
}