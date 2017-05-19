#include <iostream>
#include <array>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		array<int, 150> pos;
		int index = 0;
		int max_l = 0;
		int cur_l = 0;
		int k;
		for (int i = 0; i < pos.size(); i++)
		{
			pos[i] = -1;
		}
		while (index < s.size())
		{
			k = s[index];
			if (pos[k] == -1)
			{
				pos[k] = index;
				cur_l++;
			}
			else
			{
				int last = pos[k];
				pos[k] = index;
				if (last >= index - cur_l)
				{
					if (max_l < cur_l)
					{
						max_l = cur_l;
					}
					cur_l = index - last;
					if (s.size() - index + cur_l - 1 <= max_l)
					{
						break;
					}
				}
				else
				{
					cur_l++;
				}
			}
			index++;
		}
		if (max_l < cur_l)
		{
			max_l = cur_l;
		}
		return max_l;
	}
};

int main()
{
	int b;
	string str = "mzuxtstw12";
	cout << Solution().lengthOfLongestSubstring(str);
	cin >> b;
	
}
