#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
    	double result;
    	if(n == 0)
    	{
    		return 1;
    	}
    	if(x == 0)
    	{
    		return 0;
    	}
    	if(n > 0)
    	{
    		result = pow2(x, n);
    	}
		else
		{
			result = pow2(1 / x, -1 * n);
		}
		return result;        
    }

    double pow2(double x, int n)
    {
    	if(n == 0)
    	{
    		return 1;
    	}
    	int a;
    	if(n % 2 == 0)
    	{
    		a = n / 2;
    		double res = pow2(x, a);
    		return res * res;
    	}
    	else
    	{
    		a = n / 2;
    		double res = pow2(x, a);
    		return res * res * x;
    	}
    }
};

int main()
{
	double x = 0;
	int n = -3;
	double result = Solution().myPow(x, n);
	cout << result << endl;
	return 0;
}