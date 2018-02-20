#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.size() == 0 || cost.size() == 0|| gas.size() != cost.size())
        {
        	return -1;
        }
        vector<int> tmp;
        int total = 0;
        int sum = 0;
        int start = 0;
        int len = gas.size();
        for(int i = 0; i < len; i++)
        {
        	tmp.push_back(gas[i] - cost[i]);
        }
        for(int i = 0; i < len; i++)
        {
        	total += tmp[i];
        	if(sum < 0)
        	{
        		sum = tmp[i];
        		start = i;
        	}
        	else
        	{
        		sum += tmp[i];
        	}
        }
        return total < 0 ? -1 : start;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> gas = {2, 3, 4, 2};
	vector<int> cost = {3, 1, 3, 4};
	int res = Solution().canCompleteCircuit(gas, cost);
	cout << res << endl;
	return 0;
}