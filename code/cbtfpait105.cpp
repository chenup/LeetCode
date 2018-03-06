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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0)
        {
        	return NULL;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        int idx = 0;
        for(auto it : inorder)
        {
        	if(it == preorder[0])
        	{
        		break;
        	}
        	idx++;
        }
        vector<int> lpreorder;
        vector<int> rpreorder;
        vector<int> linorder;
        vector<int> rinorder;
        for(auto it = preorder.begin() + 1; it < preorder.begin() + 1 + idx; it++)
        {
        	lpreorder.push_back(*it);
        }
        for(auto it = preorder.begin() + 1 + idx; it < preorder.end(); it++)
        {
        	rpreorder.push_back(*it);
        }
        for(auto it = inorder.begin(); it < inorder.begin() + idx; it++)
        {
        	linorder.push_back(*it);
        }
        for(auto it = inorder.begin() + idx + 1; it < inorder.end(); it++)
        {
        	rinorder.push_back(*it);
        }
        root->left = buildTree(lpreorder, linorder);
        root->right = buildTree(rpreorder, rinorder);
        return root;
    }
};