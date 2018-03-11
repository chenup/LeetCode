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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL)
        {
        	return res;
        }
        vector<int> tmp;
        dfs(root, tmp, res);
        return res;
    }

    void dfs(TreeNode* root, vector<int> tmp, vector<string>& res)
    {
    	tmp.push_back(root->val);
    	if(root->left == NULL && root->right == NULL)
    	{
    		string str = to_string(tmp[0]);
    		for(int i = 1; i < tmp.size(); i++)
    		{
    			str += "->" + to_string(tmp[i]);
    		}
    		res.push_back(str);
    		return;
    	}
    	if(root->left)
    	{
    		dfs(root->left, tmp, res);
    	}
    	if(root->right)
    	{
    		dfs(root->right, tmp, res);
    	}
    	
    	tmp.pop_back();
    	return;
    }
};