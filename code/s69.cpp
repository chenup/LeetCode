#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int mySqrt(int x) {
        int l = 1;
        int r = x / 2 + 1;
        while(l <= r)
        {
        	int m = (l + r) / 2;
        	if(m  <= x / m && x / (m + 1) < (m + 1))
        	{
        		return m;
        	}
        	else if(x / m < m)
        	{
        		r = m - 1;
        	}
        	else
        	{
        		l = m + 1;
        	}
        }
        return 0;
    }
};


int main()
{
	int x = 0;
	int result = Solution().mySqrt(x);
	cout << result << endl;
	return 0;
}