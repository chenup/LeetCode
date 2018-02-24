#include <iostream>
#include <algorithm>

using namespace std;

static bool cmp(const string a, const string b)
{
	int len_a = a.size();
	int len_b = b.size();
	int i = 0;
	while(i < len_a && i < len_b)
	{
		if(a[i] == b[i])
		{
			i++;
		}
		else
		{
			return a[i] > b[i];
		}
		
	}
	if(len_a == len_b)
	{
		return false;
	}
	else if(len_a > len_b)
	{
		return cmp(a.substr(len_b, a.size() - len_b), b);
	}
	else
	{
		return cmp(a, b.substr(len_a, b.size() - len_a));
	}
}
    
    
class Solution {
public:
    string largestNumber(vector<int>& nums) {
  		string res = "";
  		vector<string> tmp;
  		for(auto it : nums)
  		{
  			tmp.push_back(to_string(it));
  		}
  		sort(tmp.begin(), tmp.end(), cmp);
  		for(auto it : tmp)
  		{
  			res = res + it;
  		}
  		if(res.size() != 0 && res[0] == '0')
  		{
  			return "0";
		}
  		return res;      
    }
};


int main()
{
	vector<int> nums = {3, 30, 34, 5, 9};
	string res = Solution().largestNumber(nums);
	cout << res << endl;
	return 0;
}
