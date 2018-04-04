/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//深度优先搜索，动态规划
class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> tmp;
        return dfs(root, tmp);
    }

    int dfs(TreeNode* root, unordered_map<TreeNode*, int>& tmp)
    {
    	int val = root->val;
    	if(!root)
    	{
    		return 0;
    	}
    	if(tmp.find(root) != tmp.end())
    	{
    		return tmp[root];
    	}
    	if(root->left)
    	{
    		val += dfs(root->left->left, tmp) + dfs(root->left->right, tmp);
    	}
    	if(root->right)
    	{
    		val += dfs(root->right->left, tmp) + dfs(root->right->right, tmp);
    	}
    	val = max(val, dfs(root->left, tmp) + dfs(root->right, tmp));
    	tmp[root] = val;
    	return val;
    }
};

//
class Solution {
public:
    int rob(TreeNode* root) {
    	vector<int> res = dfs(root);
    	return max(res[0], res[1]);
    }

    vector<int> dfs(TreeNode* root)
    {
    	if(!root)
    	{
    		return vector<int>(2, 0);
    	}
    	vector<int> left = dfs(root->left);
    	vector<int> right = dfs(root->right);
    	vector<int> res(2, 0);
    	res[0] = max(left[0], left[1]) + max(right[0], right[1]);
    	res[1] = left[0] + right[0] + root->val;
    	return res;
    }
};