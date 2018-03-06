#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> results;
        vector<vector<int>> resultv;
        sort(candidates.begin(), candidates.end());
        /*
        for(auto it = candidates.begin(); it != candidates.end(); it++)
        {
        	cout << *it <<endl; 
		}
		*/
        int n = candidates.size();
        if(n == 0)
        {
        	return resultv;
        }
        int end;
        int mid;
        if(target < candidates[0])
        {
        	return resultv;
        }
        else if(target > candidates[n - 1])
        {
        	end = n - 1;
        }
        else 
        {
        	//cout << candidates.size() << endl;
        	mid = findMid(candidates, 0, candidates.size() - 1 ,target);
        	//cout << mid << endl;
        	if(candidates[mid] <= target)
        	{
        		end = mid;
        	}
        	else
        	{
        		end = mid - 1;
        	}
        }
        vector<int> tmpv;
        //cout << end << endl;
		findCombination(results, candidates, tmpv, 0, end, target);
		//cout << results.size();
		for(auto it = results.begin(); it != results.end(); it++)
		{
			resultv.push_back(*it);
		}
		//cout << results.size();
		return resultv;
    }

    void findCombination(set<vector<int>>& result, vector<int>& candidates, vector<int>& tmpv, int start, int end, int target)
    {
    	for(int i = start; i <= end; i++)
    	{
    		//cout << candidates[i] << endl;
    		int left = target - candidates[i];
    		if(left == 0)
    		{
    			if(i != 0 && candidates[i - 1] == candidates[i] && tmpv.size() == 0)
    			{
    				return;
    			}
    			//cout << candidates[i] << endl; 
    		//	cout << candidates[i] << endl;
    			tmpv.push_back(candidates[i]);
    			//vector<int> stmpv;
    			/*
    			for(auto it = tmpv.end() - 1; it != tmpv.begin() - 1; it--)
    			{
    				stmpv.push_back(*it);
				}
				*/
    			result.insert(tmpv);
    			tmpv.pop_back();
    			return;
    		}
    		else if(left < 0)
    		{
    			return;
    		}
    		else
    		{
    			if(i != 0 && candidates[i - 1] == candidates[i])
				{ 
					if(tmpv.size() == 0)
					{
						continue;
					}
					else if(tmpv.size() != 0 && tmpv[tmpv.size() - 1] != candidates[i])
					{
						continue;
					}
    			
    			}
    			//if(tmpv.size() == 0)
				//cout << candidates[i] << endl; 
    			tmpv.push_back(candidates[i]);
    			findCombination(result, candidates, tmpv, i + 1, end, left);
    			tmpv.pop_back();
    		}
    		
    	}
    }

    int findMid(vector<int>& candidates, int s, int e, int target)
    {
    	if(s == e)
    	{
    		return s;
    	}
    	if(s > e)
    	{
    	//	cout << "hello" << endl;
    		return -1;
    	}
    	int mid = (s + e) / 2;
    //	cout << "mid" << mid << endl;
    	if(candidates[mid] > target)
    	{
    		if(s == mid)
    		{
    			return mid;
    		}	
    		return findMid(candidates, s, mid - 1, target);
    	}
    	else if(candidates[mid] < target)
    	{
    		if(e == mid)
    		{
    			return mid;
    		}
    		return findMid(candidates, mid + 1, e, target);
    	}
    	else
    	{
    		return mid;
    	}
    }
};

int main()
{
	vector<int> candidates = {3,5,1,1};
	int target = 2;
	vector<vector<int>> result = Solution().combinationSum2(candidates, target);
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