#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX_INT pow(2, 31) - 1
#define MIN_INT pow(2, 31) * -1 
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0 || (dividend == MIN_INT && divisor == -1))
        {
        	return MAX_INT;
        }
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        long long m = abs((long long)dividend);
        long long n = abs((long long)divisor);
        int result = 0;
        while(m >= n)
        {
        	long long p = 1;
        	long long tmp = n;
        	while(m >= (tmp << 1))
        	{
        		tmp = tmp << 1;
        		p = p << 1;
        	}
        	result += p;
        	m -= tmp;
        }

        return result * sign;
    }
};

int main()
{
	int dividend = -55;
	int divisor = 3;
	int result = Solution().divide(dividend, divisor);
	cout << result << endl;
	return 0;
}