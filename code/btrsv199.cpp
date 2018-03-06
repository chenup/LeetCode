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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        vector<TreeNode*> queue;
        if(root == NULL)
        {
        	return res;
        }
        int idx = 0;
        int next = 1;
        int height = 0;
        TreeNode* p = NULL;
        queue.push_back(root);
        while(idx < queue.size())
        {
        	TreeNode *tmp = queue[idx];
        	if(tmp == p)
        	{
        		height++;
        		res.push_back(queue[idx - 1]->val);
        	}
        	if(tmp->left)
        	{
        		if(height == next - 1)
        		{
        			next++;
        			p = tmp->left;
        		}
        		queue.push_back(tmp->left);
        	}
        	if(tmp->right)
        	{
        		if(height == next - 1)
        		{
        			next++;
        			p = tmp->right;
        		}
        		queue.push_back(tmp->right);
        	}
        	idx++;
        }
        res.push_back(queue[idx - 1]->val);
        return res;
    }
};