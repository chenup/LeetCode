#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(); 
        vector<vector<int>> result;
        vector<int> tmp;
        result.push_back(tmp);
        getCombine(nums, result, 1, n, tmp);
        return result;
    }

    void getCombine(vector<int>& nums, vector<vector<int>>& result, int s, int n, vector<int>& tmp)
    {
        if(s > n)
        {
            
            return;
        }
        for(int i = s; i <= n; i++)
        {
            tmp.push_back(nums[i - 1]);
            result.push_back(tmp);
            getCombine(nums, result, i + 1, n, tmp);
            tmp.pop_back();
        }
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> result = Solution().subsets(nums);
    for(auto it : result)
    {
        for(auto itt : it)
        {
            cout << itt << " ";
        }
        cout << endl;
    }
    return 0;
}