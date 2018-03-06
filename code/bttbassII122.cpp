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
        int tmp;
        for(auto it : prices)
        {
        	if(it < buy)
        	{
        		buy = it;
        	}
        	else if(it > buy)
        	{
        		tmp = it - buy;
        		profit += tmp;
        		buy = it;
        	}
        }
        return profit;
    } 
};

int main(int argc, char const *argv[])
{
	vector<int> prices = {7, 4, 5, 3, 1, 6, 0, 4};
	int result = Solution().maxProfit(prices);
	cout << result << endl;
	return 0;
}