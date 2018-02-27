#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
 
class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        vector<bool> tmp(n - 1, true);
        if(n <= 1)
        {
        	return 0;
        }
        tmp[0] = false;
        int k = sqrt(n);
        for(int i = 2; i <= k; i++)
        {
        	if(tmp[i - 1])
        	{
        		int count = 2;
        		int product = 1;
        		while(product < n)
        		{
        			tmp[product - 1] = false;
        			product = count * i;
        			count++; 
        		}
        	}
        }
        for(auto it : tmp)
        {
        	if(it)
        	{
        		res++;
        	}
        }
        return res;
    }
};
int main()
{
	int n = 10;
	cout << Solution().countPrimes(n);
	return 0;
}