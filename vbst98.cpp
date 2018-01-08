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
    bool isValidBST(TreeNode* root) {
    	vector<int> result;
    	bool flag;
    	flag = subTree(result, root);
    	return flag;
    }

    bool subTree(vector<int>& result, TreeNode* root)
    {
    	if(root == NULL)
    	{
    		return true;
    	}
    	bool flag;
    	flag = subTree(result, root->left);
    	if(flag == false)
    	{
    		return false;
    	}
    	if(result.size() != 0 && root->val <= result[result.size() - 1])
    	{
    		return false;
    	}
    	else
    	{
    		result.push_back(root->val);
    	}
    	flag = subTree(result, root->right);
    	return flag;

    }
};

int main()
{
	TreeNode root = TreeNode(1);
	TreeNode l1 = TreeNode(2);
	TreeNode l2 = TreeNode(3);
	root.left = &l1;
	root.right = &l2;
	bool result = Solution().isValidBST(NULL);
	cout << result << endl;
	return 0;
}