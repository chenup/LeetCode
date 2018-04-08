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
    TreeNode* pruneTree(TreeNode* root) {
        if(isContain(root))
        {
        	return root;
        }
        return NULL;
    }

    bool isContain(TreeNode* root)
    {
    	if(root == NULL)
    	{
    		return true;
    	}
    	if(!isContain(root->left))
    	{
    		root->left = NULL;
    	}
    	if(!isContain(root->right))
    	{
    		root->right = NULL;
    	}
    	if(root->left == NULL && root->right == NULL)
    	{
    		return root->val == 1;
    	}
        return true;
    }
};