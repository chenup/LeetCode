class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n <= 1)
        {
        	return 0;
        }
        vector<int> tmp(n, 0);
        tmp[0] = cost[0];
        tmp[1] = cost[1];
        for(int i = 2; i < n; i++)
        {
        	tmp[i] = min(tmp[i - 1], tmp[i - 2]) + cost[i];
        }
        return min(tmp[n - 1], tmp[n - 2]);
    }
};