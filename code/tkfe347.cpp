/*
bool cmp(const pair<int, int>& lhs, const pair<int, int>& rhs)
{
	return lhs.second > rhs.second; 
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
    	unordered_map<int, int> tmp;
    	vector<int> res;
    	for(auto a : nums)
    	{
    		tmp[a]++;
    	}    
    	vector<pair<int, int>> t(tmp.begin(), tmp.end());
    	sort(t.begin(), t.end(), cmp);
    	for(int i = 0; i < k; i++)
    	{
    		res.push_back(t[i].first);
    	}
    	return res;
    }
};
*/
//堆排序
/*
class Solution
{
public:
	vector<int> topKFrequent(vector<int>& nums, int k)
	{
		unordered_map<int, int> tmp;
		priority_queue<pair<int, int>> max_heap;
		vector<int> res;
		for(auto it : nums)
		{
			tmp[it]++;
		}
		for(auto it : tmp)
		{
			max_heap.push({it.second, it.first});
		}
		for(int i = 0; i < k; i++)
		{
			res.push_back(max_heap.top().second);
			max_heap.pop();
		}
		return res;
	}
};
*/
//桶排序
class Solution
{
	vector<int> topKFrequent(vector<int>& nums, int k)
	{
		vector<int> res;
		vector<vector<int>> bucket(nums.size() + 1);
		unordered_map<int, int> tmp;
		for(auto it : nums)
		{
			tmp[it]++;
		}
		for(auto it : tmp)
		{
			bucket[tmp.second].push_back(it.first);
		}
		for(int i = nums.size(); i >= 0; i--)
		{
			for(int j = 0; j < bucket[i]; j++)
			{
				res.push_back(bucket[i][j]);
				if(res.size() == k) 
				{
					return res;
				}
			}
		}
	}
};
