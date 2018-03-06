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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int result = 0;
        if(root == NULL)
        {
        	return sum;
        }
        result = result * 10 + root->val;
        if(root->left == NULL && root->right == NULL)
        {
            sum += result;
        }
        childTree(root->left, result, sum);
        childTree(root->right, result, sum);
        return sum;
    }

    void childTree(TreeNode* root, int result, int& sum)
    {
    	if(root == NULL)
        {
        	return;
        }
        result = result * 10 + root->val;
        if(root->left == NULL && root->right == NULL)
        {
            sum += result;
        }
        childTree(root->left, result, sum);
        childTree(root->right, result, sum);
    	return;
    }
};