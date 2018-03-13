// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

enum Status{Valid = 0, Invalid};

int runStatus = Valid;

class Solution {
public:
    int firstBadVersion(int n) {
        if(n == 0)
        {
        	runStatus = Invalid;
        	return 0;
        }
        int res = helper(1, n);
        return res;
    }

    int helper(int lo, int hi)
    {
    	if(lo > hi)
    	{
    		return lo + (hi - lo) / 2;  
    	}
    	int mid = lo + (hi - lo) / 2;
    	if(isBadVersion(mid))
    	{
    		return helper(lo, mid - 1);
    	}
    	else
    	{
    		return helper(mid + 1, hi);
    	}
    }
};