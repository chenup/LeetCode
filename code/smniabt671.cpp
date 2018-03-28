/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
       	int min;
       	if(root == NULL)
       	{
       		return -1;
       	}
       	min = root->val;
    	int left = helper(root->left, min);
    	int right = helper(root->right, min);
    	if(left != -1 && right != -1)
    	{
    		return left < right ? left : right;
    	}
    	else if(left != -1)
    	{
    		return left;
    	}
    	return right;
    }

    int helper(TreeNode* root, int min)
    {
    	if(root == NULL)
    	{
    		return -1;
    	}
    	if(root->val > min)
    	{
    		return root->val;
    	}
    	int left = helper(root->left, min);
    	int right = helper(root->right, min);
    	if(left != -1 && right != -1)
    	{
    		return left < right ? left : right;
    	}
    	else if(left != -1)
    	{
    		return left;
    	}
    	return right;
    }
};