class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) 
    {
    	unordered_map<string, multiset<string>> tmp;
    	vector<string> res;
     	for(auto it : tickets)
     	{
     		tmp[it.first].insert(it.second);
     	}
     	dfs(tmp, "JFK", res);
     	return vector<string>(res.rbegin(), res.rend());
    }

    void dfs(unordered_map<string, multiset<string>> &tmp, string t, vector<string> &res)
    {
    	while(tmp[t].size())
    	{
    		auto it = tmp[t].begin();
    		tmp[t].erase(it);
    		dfs(tmp, *it, res);
    	}
    	res.push_back(t);
    }
};