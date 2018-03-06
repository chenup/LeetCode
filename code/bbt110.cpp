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
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
        {
        	return true;
        }
        pair<bool, int> lpair = getBH(root->left);
        pair<bool, int> rpair = getBH(root->right);
        if(lpair.first && rpair.first)
        {
        	int result = lpair.second - rpair.second;
        	if(result == -1 || result == 0 || result == 1)
        	{
        		return true;
        	}
        	else
        	{
        		return false;
        	}
        }
        else
        {
        	return false;
        }
    }

    pair<bool, int> getBH(TreeNode* root)
    {
    	if(root == NULL)
    	{
    		return make_pair(true, 0);
    	}
    	pair<bool, int> lpair = getBH(root->left);
        pair<bool, int> rpair = getBH(root->right);
        if(lpair.first && rpair.first)
        {
        	int result = lpair.second - rpair.second;
        	if(result == -1 || result == 0 || result == 1)
        	{
        		if(lpair.second >= rpair.second)
        		{
        			return make_pair(true, lpair.second + 1);
        		}
        		else
        		{
        			return make_pair(true, rpair.second + 1);
        		}
        	}
        	else
        	{
        		return make_pair(false, -1);
        	}
        }
        else
        {
        	return make_pair(false, -1);
        }
    }
};