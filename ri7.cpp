#include <iostream>
#include <cstring>
using namespace std;
class Solution{
public:
	int reverse(int x)
	{
		char buf[20];
		long long result;
		sprintf(buf, "%d", x);
		char tmp;
		int len = strlen(buf);
		int i, j;
		if(buf[0] == '-')
		{
			for(int i = 0; i < (len - 1) / 2 ; i++)
			{
				tmp = buf[i + 1];
				buf[i + 1] = buf[len - 1 - i];
				buf[len - 1 - i] = tmp;
	 		}
		}
		else
		{
			for(int i = 0; i < len / 2 ; i++)
			{
				tmp = buf[i];
				buf[i] = buf[len - i - 1];
				buf[len - i - 1] = tmp;
	 		}
		}
		sscanf(buf, "%lld", &result);
		if(result > 2147483647 || result < -2147483648)
		{
			result = 0;
		}
		return result;
	}
};

int main()
{
	int x;
	int result;
	cin >> x;
	result = Solution().reverse(x);
	cout << result;
	return 0;
}