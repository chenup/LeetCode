class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num > 0 && (log10(num) / log10(4) - int(log10(num) / log10(4))) == 0)
        {
        	return true;
        }
        return false;
    }
};