class NumArray {
public:
    NumArray(vector<int> nums) : num(vector<int>(nums.size() + 1, 0)), cache(vector<int>(nums.size() + 1, 0)){
        for(int i = 0; i < nums.size(); i++)
        {
            update(i, nums[i]);
        }
    }

    int lowbit(int k)
    {
    	return k & (-1 * k);
    }

    void update(int i, int val) {
    	int delta = val - num[i + 1];
        for(int k = i + 1; k < num.size(); k += lowbit(k))
        {
        	cache[k] += delta;
        }
        num[i + 1] = val;
    }
    
    int getSum(int k)
    {
    	int sum = 0;
    	for(int i = k; i >= 1; i -= lowbit(i))
        {
        	sum += cache[i];
        }
        return sum;
    }

    int sumRange(int i, int j) {
        return getSum(j + 1) - getSum(i);
    }
private:
	vector<int> cache;
    vector<int> num;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */