#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
        {
        	return 0;
        }
        int profit = 0;
        int buy = prices[0];
        int sell = buy;
        int tmp;
        for(auto it : prices)
        {
        	if(it < buy)
        	{
        		tmp = sell - buy;
        		if(tmp > profit)
        		{
        			profit = tmp;
        		}
        		buy = it;
        		sell = it;
        	}
        	else if(it > sell)
        	{
        		sell = it;
        	}
        }
        tmp = sell - buy;
        if(tmp > profit)
        {
        	profit = tmp;
        }
        return profit;
    }
};

int main()
{
	vector<int> prices = {7, 4, 5, 3, 1, 6, 0, 4};
	int result = Solution().maxProfit(prices);
	cout << result << endl;
	return 0;
}