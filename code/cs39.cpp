#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        if(n == 0)
        {
        	return result;
        }
        int end;
        int mid;
        if(target < candidates[0])
        {
        	return result;
        }
        else if(target > candidates[n - 1])
        {
        	end = n - 1;
        }
        else 
        {
        	mid = findMid(candidates, 0, candidates.size() - 1 ,target);
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
		findCombination(result, candidates, tmpv, 0, end, target);
		return result;
    }

    void findCombination( vector<vector<int>>& result, vector<int>& candidates, vector<int>& tmpv, int start, int end, int target)
    {
    	for(int i = start; i <= end; i++)
    	{
    		//cout << candidates[i] << endl;
    		int left = target - candidates[i];
    		if(left == 0)
    		{
    			tmpv.push_back(candidates[i]);
    			//vector<int> stmpv;
    			/*
    			for(auto it = tmpv.end() - 1; it != tmpv.begin() - 1; it--)
    			{
    				stmpv.push_back(*it);
				}
				*/
    			result.push_back(tmpv);
    			tmpv.pop_back();
    			return;
    		}
    		else if(left < 0)
    		{
    			return;
    		}
    		else
    		{
    			tmpv.push_back(candidates[i]);
    			findCombination(result, candidates, tmpv, i, end, left);
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
    		return -1;
    	}
    	int mid = (s + e) / 2;
    	if(candidates[mid] > target)
    	{
    		return findMid(candidates, s, mid - 1, target);
    	}
    	else if(candidates[mid] < target)
    	{
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
	vector<int> candidates = {1,2,3,6,7};
	int target = 7;
	vector<vector<int>> result = Solution().combinationSum(candidates, target);
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