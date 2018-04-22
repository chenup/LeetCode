#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
 
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
    	    vector<pair<int, int>> res;
    	    map<int, set<pair<int, int>>> r;
    	    int tmp;
    	    int pos1;
    	    int pos2;
            if(nums1.empty() || nums2.empty())
            {
                return res;
            }
    	    tmp = nums1[0] + nums2[0];
    	    r[tmp].insert({0, 0});
    	    for(int i = 0; i < k; i++)
    	    {
                if(r.empty())
                {
                    return res;
                }
    	    	auto it = r.begin();
    	    	auto t = (*it).second.begin();
	    		res.push_back({nums1[(*t).first], nums2[(*t).second]});
	    		pos1 = (*t).first;
	    		pos2 = (*t).second;
                (*it).second.erase(*t);
	    		if(i < nums1.size() - 1)
	    		{
	    		
	    			tmp = nums1[i + 1] + nums2[0];
	    			r[tmp].insert({i + 1, 0});
	    		}
	    		if(pos2 < nums2.size() - 1)
	    		{
	    			tmp = nums1[pos1] + nums2[pos2 + 1];
	    			r[tmp].insert({pos1, pos2 + 1});
	    		}
    	    	if((*it).second.empty())
    	    	{
    	    		r.erase((*it).first);
    	    	}
    	    }
    	    return res;
    }
};

int main()
{
	vector<int> nums1 = {1,1,2};
	vector<int> nums2 = {1,2,3};
	int k = 10;
	vector<pair<int, int>> res = Solution().kSmallestPairs(nums1, nums2, k);
	for(auto it : res)
	{
		cout << it.first << " " << it.second << endl;
	}
	return 0;
}