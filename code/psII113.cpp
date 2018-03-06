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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    	vector<vector<int>> vec;
    	vector<int> tmp;
        int result = 0;
        if(root == NULL)
        {
        	return vec;
        }
        result += root->val;
        tmp.push_back(root->val);
        if(root->left == NULL && root->right == NULL)
        {
        	if(result == sum)
        	{
        		vec.push_back(tmp);
        	}
        }
        childTree(vec, tmp, root->left, result, sum);
        childTree(vec, tmp, root->right, result, sum);
        return vec;
    }

    void childTree(vector<vector<int>>& vec, vector<int>& tmp, TreeNode* root, int result, int sum)
    {
    	if(root == NULL)
        {
        	return;
        }
        result += root->val;
        tmp.push_back(root->val);
        if(root->left == NULL && root->right == NULL)
        {
        	if(result == sum)
        	{
        		vec.push_back(tmp);
        	}
        }
        childTree(vec, tmp, root->left, result, sum);
        childTree(vec, tmp, root->right, result, sum);
        result -= root->val;
        tmp.pop_back();
    	return;
    }
};