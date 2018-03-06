/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
enum Status = {Valid = 0, InValid};

int status = Valid;

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL || k == 0)
        {
        	status = InValid;
        	return 0;
        }
        int res = 0;
        helper(root, k, res);
        return res;
    }

    void helper(TreeNode* root, int& k, int& res)
    {
    	if(root == NULL)
    	{
    		return;
    	}
    	TreeNode(root->left, k);
    	if(k == 1)
    	{
    		res = root->val;
    		return
    	}
    	k--;
    	TreeNode(root->right, k);
    }
};