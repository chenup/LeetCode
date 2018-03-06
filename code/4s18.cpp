#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        map<int, vector<pair<int, int>>> table;
        if(nums.size() < 4)
        {
        	return result;
        }
        for(int i = 0; i < nums.size() - 1; i++)
        {
        	for(int j = i + 1; j < nums.size(); j++)
        	{
        		int sum = nums[i] + nums[j];
        		auto it = table.find(sum);
        		if(it != table.end())
        		{
        			table[sum].push_back(make_pair(i, j));
        		}
        		else
        		{
        			vector<pair<int, int>> tmp;
        			tmp.push_back(make_pair(i, j));
        			table[sum] = tmp;
        		}
        	}
        }
        set<set<int>> s;
        for(auto it = table.begin(); it != table.end(); it++)
        {
        	int n = target - (*it).first;
        	if(table.find(n) != table.end())
        	{

        		for(auto itt = (*it).second.begin(); itt != (*it).second.end(); itt++)
        		{
        			for(auto ittt = table[n].begin(); ittt != table[n].end(); ittt++)
        			{
        				set<int> tmp;
        				tmp.insert((*itt).first);
        				tmp.insert((*itt).second);
        				tmp.insert((*ittt).first);
        				tmp.insert((*ittt).second);
        				if(tmp.size() == 4)
        				{
        					s.insert(tmp);
        				}
        			}
        		}

        	}
        }
        set<vector<int>> rs;
        for(auto it = s.begin(); it != s.end(); it++)
        {
        	vector<int> tmp;
        	for(auto itt = (*it).begin(); itt != (*it).end(); itt++)
        	{
        		tmp.push_back(nums[*itt]);
        	}
        	sort(tmp.begin(), tmp.end());
        	rs.insert(tmp);
        }
        for(auto it = rs.begin(); it != rs.end(); it++)
        {
        	result.push_back(*it);
        }
        return result;
    }
};


int main()
{
	vector<int> nums = {1, 0, -1, 0, -2, 2};
	int target = 0;
	vector<vector<int>> result = Solution().fourSum(nums, target);
	for(auto it = result.begin(); it != result.end(); it++)
	{
		for(auto itt = (*it).begin(); itt != (*it).end(); itt++)
		{
			cout << *itt << " ";
		}
		cout << endl;
	}
	return 0;
}