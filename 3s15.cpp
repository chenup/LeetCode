#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		auto it = nums.begin();
		while(it != nums.end())
		{
			auto l = it + 1;
			auto r = nums.end() - 1;
			while(l < r)
			{
				if( *l + *r + *it == 0)
				{
					vector<int> tmp;
					tmp.push_back(*it);
					tmp.push_back(*l);
					tmp.push_back(*r);
					result.push_back(tmp);
					while(l < r && *l == *(l + 1))
					{
						l++;
					}
					while(l < r && *r == *(r - 1))
					{
						r--;
					}
					l++;
					r--;

				}
				else if(*l + *r + *it < 0)
				{
					while(l < r && *l == *(l + 1))
					{
						l++;
					}
					l++;
				}
				else
				{
					while(l < r && *r == *(r - 1))
					{
						r--;
					}
					r--;
				}
			}
			while(it < nums.end() - 1 && *it == *(it + 1))
			{
				it++;
			}
			it++;
		}
		return result;
		/*
		sort(nums.begin(), nums.end());
		vector<vector<int>> vvi;
		int n[3];
		int flag;
		if(nums.size() < 3 || *(nums.begin()) > 0 || *(nums.end()) < 0)
		{
			return vvi;
		}
		vector<int> next;
		for(int k = 0; k < nums.size(); k++)
		{
			if(k == nums.size() - 1)
			{
				next.push_back(k);
				break;
			}
			if(nums[k] != nums[k + 1])
			{
				next.push_back(k);
			}
		}
		int p = 0;
		int len = next.size();
		while(p < len)
		{
			
			if(nums[next[p]] > 0)
			{
				break;
			}
			n[0] = nums[next[p]];
			int q;
			if(p == 0)
			{	
				if(next[0] >= 1)
				{
					q = 0;
				}
				else
				{
					q = 1;
				}
			}
			else
			{
				if(next[p] - next[p - 1] >= 2)
				{
					q = p;
				}
				else
				{
					q = p + 1; 
				} 
			}
			int c;
			int flag = 0;
			while(q < len)
			{
				c = nums[next[q]] + nums[next[p]];
				if(c > 0 && nums[next[q]] > 0)
				{
					break;
				}
				n[1] = nums[next[q]];
				int o;
				if(q == 0)
				{	
					if(next[0] >= 2)
					{
						o = 0;
					}
					else
					{
						o = 1;
					}
				}
				else
				{
					if(next[q] - next[q - 1] >= 3)
					{
						o = q;
					}
					else if( p!=q && next[q] - next[q - 1] == 2)
					{
						o = q;
					}
					else
					{
						o = q + 1; 
					} 
				}
				while(o < len)
				{
					int r = nums[next[o]];
					if(r == c * -1)
					{
						n[2] = r;
						vector<int> v;
						v.push_back(n[0]);
						v.push_back(n[1]);
						v.push_back(n[2]);
						vvi.push_back(v);
						break;
					}
					if(r > c * -1)
					{
						break;
					}
					o = o + 1;
				}
				q = q + 1;
			}
			
			p = p + 1;
		}
		return vvi;
		*/
	}
};

int main()
{
	vector<int> nums = {-3,1,-5,2,-4,2,-1,1,-5,-1,4};
	auto vvi = Solution().threeSum(nums);
	for(auto &v : vvi)
	{
		for(auto a = v.begin(); a != v.end(); a++)
		{
			cout << *a << " ";
		}
		cout << endl;
	}
	return 0;
}