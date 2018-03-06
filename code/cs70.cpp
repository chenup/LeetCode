#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int climbStairs(int n) {
        if(n == 0)
        {
        	return 0;
        }
        if(n == 1)
        {
        	return 1;
        }
        if(n == 2)
        {
        	return 2;
        }
        int fn, fn_1 = 2, fn_2 = 1;
        for(int i = 3; i <= n; i++)
        {
        	fn = fn_1 + fn_2;
        	fn_2 = fn_1;
        	fn_1 = fn;
        }
        return fn;
    }
};

int main()
{
	int n = 4;
	int result = Solution().climbStairs(n); 
	cout << result << endl;
	return 0;
}