#include <iostream>
#include <algorithm>

using namespace std;
 
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        int tmp = m ^ n;
        int count = -1;
        while(tmp)
        {
        	tmp = tmp >> 1;
        	count++;
        }
        if(count == -1)
        {
        	return m;
        }
        else
        {
        	long long int mask = (1 << (count + 1)) - 1;
        	res = m & (~mask);
        }
        return res;
    }
};

int main()
{
	int m = 0; 
	int n = 2147483647;
	cout << Solution().rangeBitwiseAnd(m, n);
	return 0;
}