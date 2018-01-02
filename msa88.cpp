#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i;
        int j;
        auto b = nums2.begin();
        auto a = nums1.begin();
        int p = nums1.size();
		while(p > m)
		{
			nums1.pop_back();
			p--;	
		} 
        for(i = 0, j = 0; i < m && j < n;)
        {
        
        	a = nums1.begin();
        	if(*(a + i) <= *(b + j))
        	{
        		i++;
        	}
        	else
        	{
        		nums1.insert(a + i, *(b + j));
        		i++;
        		m++;
        		j++;
        	}
        }
        
        while(j < n)
        {
        	a = nums1.begin();
        	nums1.insert(a + m, *(b + j));
        	m++;
        	j++;
        }
        
    }
};

int main()
{
	vector<int> nums1 = {1, 2, 3, 0, 0, 0};
	int m = 3;
	vector<int> nums2 = {4, 5, 6};
	int n = 3;
	Solution().merge(nums1, m, nums2, n);
	for(auto v : nums1)
	{
		cout << v << endl;
	}
	return 0;
}