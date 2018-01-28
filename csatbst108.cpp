#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        vector<int> leftv;
        vector<int> rightv;
        int size = nums.size();
        if(size == 0)
        {
        	return NULL;
		}
        leftv.assign(nums.begin(), nums.begin() + size / 2);
        rightv.assign(nums.begin() + size / 2 + 1, nums.end());
        TreeNode* root = new TreeNode(nums[size / 2]);
        root->left = sortedArrayToBST(leftv);
        root->right = sortedArrayToBST(rightv);
        return root;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> nums = {-10,-3,0,5,9};
	TreeNode* root = Solution().sortedArrayToBST(nums);
	return 0;
}