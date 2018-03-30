class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(target < letters[0] || target >= letters.back())
        {
        	return letters[0];
        }
        return binarySearch(letters, 0, letters.size() - 1, target);
    }
    char binarySearch(vector<char>& letters, int lo, int hi, char target)
    {

    	int mid = lo + (hi - lo) / 2;
    	if(lo > hi)
    	{
    		return letters[mid]; 
    	}
    	if(letters[mid] <= target)
    	{
    		return binarySearch(letters, mid + 1, hi, target);
    	}
    	else
    	{
    		return binarySearch(letters, lo, mid - 1, target);
    	}
    }
};