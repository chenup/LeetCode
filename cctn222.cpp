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
    int countNodes(TreeNode* root) {
   		if(root == NULL)
   		{
   			return 0;
   		}
   		int leftLen = getLeftHeight(root->left);
   		int rightLen = getRightHeight(root->right);
   		if(leftLen == rightLen)
   		{
   			return pow(2, leftLen + 1) - 1;
   		}
   		else
   		{
   			return countNodes(root->left) + countNodes(root->right) + 1;
   		}
    }

    int getLeftHeight(TreeNode* root)
    {
    	if(root == NULL)
    	{
    		return 0;
    	}
    	return getLeftHeight(root->left) + 1;
    }

    int getRightHeight(TreeNode* root)
    {
    	if(root == NULL)
    	{
    		return 0;
    	}
    	return getRightHeight(root->right) + 1;
    }
};