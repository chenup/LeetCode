//暴力求解
/*
class NumArray {
public:
    NumArray(vector<int> nums) : nums(nums){
        
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        for(int k = i; k <= j; k++)
        {
        	sum += nums[k];
        }
        return sum;
    }
private:
	vector<int> nums;
};
*/

//用cache
class NumArray {
public:
    NumArray(vector<int> nums) : cache(vector<int>(nums.size() + 1, 0)){
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
        	sum += nums[i];
        	cache[i + 1] = sum;
        } 
    }
    
    int sumRange(int i, int j) {
        return cache[j + 1] - cache[i];
    }
private:
	vector<int> cache;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */