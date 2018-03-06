#include <iostream>
#include <cstring>

using namespace std;

class Solution{
public:
	bool isPalindrome(int x){
		char buf[30];
		sprintf(buf, "%d", x);
		int size = strlen(buf);
		for(int i = 0; i < size / 2; i++)
		{
			if(buf[i] != buf[size - i - 1])
			{
				return false;
			}
		}
		return true;
	}

};

int main()
{
	int x;
	bool flag;
	cin >> x;
	flag = Solution().isPalindrome(x);
	cout << flag;
}