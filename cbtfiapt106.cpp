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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size() == 0)
        {
        	return NULL;
        }
        int len = postorder.size();
        TreeNode* root = new TreeNode(postorder[len - 1]);
        int idx = 0;
        for(auto it : inorder)
        {
        	if(it == postorder[len - 1])
        	{
        		break;
        	}
        	idx++;
        }
        vector<int> lpostorder;
        vector<int> rpostorder;
        vector<int> linorder;
        vector<int> rinorder;
        for(auto it = postorder.begin(); it < postorder.begin() + idx; it++)
        {
        	lpostorder.push_back(*it);
        }
        for(auto it = postorder.begin() + idx; it < postorder.end() - 1; it++)
        {
        	rpostorder.push_back(*it);
        }
        for(auto it = inorder.begin(); it < inorder.begin() + idx; it++)
        {
        	linorder.push_back(*it);
        }
        for(auto it = inorder.begin() + idx + 1; it < inorder.end(); it++)
        {
        	rinorder.push_back(*it);
        }
        root->left = buildTree(linorder, lpostorder);
        root->right = buildTree(rinorder, rpostorder);
        return root;
    }
};