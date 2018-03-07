/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
        {
        	return NULL;
        }
        vector<TreeNode*> ancestor1;
        vector<TreeNode*> ancestor2;
        if(!findTreeNode(root, p, ancestor) || !findTreeNode(root, q, ancestor))
        {
        	return NULL;
        }
        for(auto it = ancestor1.begin(); it != ancestor1.end(); it--)
        {
        	if(ancestor2.find(*it) != ancestor2.end())
        	{
        		return *it;
        	}
        }
        return NULL;
    }

    bool findTreeNode(TreeNode* root, TreeNode* p, vector<TreeNode*>& ancestor)
    {
    	if(root == NULL)
    	{
    		return false;
    	}
    	if(root == p)
    	{
    		ancestor.push_back(root);
    		return true;
    	}
    	if(findTreeNode(root->left, ancestor) || findTreeNode(root->right, p, ancestor))
    	{
    		ancestor.push_back(root);
    		return true;
    	}
    	return false;
    }
};
*/
/*
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	if(root == NULL)
    	{
    		return NULL;
    	}
    	if(p->val < root->val && q->val < root->val)
    	{
    		return lowestCommonAncestor(root->left, p, q);
    	}
    	if(p->val > root->val && q->val > root->val)
    	{
    		return lowestCommonAncestor(root->right, p, q);
    	}
    	return root;
    }
};
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	if(root == NULL || p == root || q == root)
    	{
    		return root;
    	}
    	TreeNode* left = lowestCommonAncestor(root->left, p, q);
    	TreeNode* right = lowestCommonAncestor(root->right, p, q);
    	if(left && right)
    	{
    		return root;
    	}
    	return left == NULL ? right:left;
    }
}; 