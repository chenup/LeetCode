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
    bool hasPathSum(TreeNode* root, int sum) {
        int result = 0;
        if(root == NULL)
        {
        	return false;
        }
        result += root->val;
        if(root->left == NULL && root->right == NULL)
        {
        	return result == sum;
        }
        return childTree(root->left, result, sum) || childTree(root->right, result, sum);
    }

    bool childTree(TreeNode* root, int result, int sum)
    {
    	if(root == NULL)
        {
        	return false;
        }
        result += root->val;
        if(root->left == NULL && root->right == NULL)
        {
        	return result == sum;
        }
        if(childTree(root->left, result, sum) || childTree(root->right, result, sum))
        {
        	return true;
        }
        result -= root->val;
    	return false;
    }
};