//从叶子结点开始一层一层剥洋葱(广度优先搜索)
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) 
    {
    	vector<int> res;
    	if(n <= 2)
    	{
    		for(int k = 0; k < n; k++)
    		{
    			res.push_back(k);
    		}
    	}
    	else
    	{
    		vector<unordered_set<int>> tmp(n);
        	queue<int> vq;
        	for(auto it : edges)
        	{
	        	tmp[it.first].insert(it.second);
	        	tmp[it.second].insert(it.first);
	        }
	       	int i = 0;
	        for(auto it : tmp)
	        {
	        	if(it.size() == 1)
	        	{
	        		vq.push(i);
	        	}
	        	i++;
	        }
	        while(n > 2)
	        {
	        	int m = vq.size();
	        	n -= m;
	        	for(int j = 0; j < m; j++)
	        	{
	        		int v = vq.front();
	        		vq.pop();
                    int it = *tmp[v].begin();
                    tmp[v].erase(it);
                    tmp[it].erase(v);
                    if(tmp[it].size() == 1)
                    {
                        vq.push(it);
                    }
	        	}
	        }
	        while(!vq.empty())
	        {
                int v = vq.front();
                vq.pop();
	        	res.push_back(v);
	        }
    	}      
        return res;
    }
};

//算图的最大半径(深度优先搜索，广度也行)
/*
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) 
    {
        
    }
};
*/