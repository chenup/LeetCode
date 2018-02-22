#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
  		int sum = 0;
  		int i = 1;
  		while(1)
  		{
  			int tmp = n / pow(5, i);
  			if(tmp == 0)
  			{
  				return sum;
  			}
  			else
  			{
  				sum += tmp;
  			}
  			i++;
  		}
	}
};

int main(int argc, char const *argv[])
{
	int n = 30;
	int res = Solution().trailingZeroes(n);
	cout << res << endl;
	return 0;
}