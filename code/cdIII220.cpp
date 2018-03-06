enum Status {Valid = 0, InValid};

int status = Valid;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k <= 0)
        {
            status = InValid;
            return false;
        }
        if(nums.size() == 0)
        {
            return false;
        }
        map<long long int, int> windowMap;
        int j = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i - j > k)
            {
                windowMap.erase(nums[j++]);
            }
            auto it = windowMap.lower_bound((long long int)nums[i] - t);
            if(it != windowMap.end() && abs(nums[i] - it->first) <= t)
            {
                return true;
            }
            windowMap[nums[i]] = i; 
        }
        return false;
    }
};