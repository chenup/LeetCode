// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        return binarySearch(1, n);
    }

    int binarySearch(int low, int hi)
    {
    	int mid = low + (hi - low) / 2;
    	int ret = guess(mid);
    	if(ret == 0)
    	{
    		return mid;
    	}
    	else if(ret == 1)
    	{
    		return binarySearch(mid + 1, hi);
    	}
    	else if(ret == -1)
    	{
    		return binarySearch(low, mid - 1);
    	}
    }
};