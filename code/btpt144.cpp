class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
    	vector<TreeNode*> stack;
    	vector<int> result;
    	if(root == NULL)
    	{
    		return result;
    	}
    	stack.push_back(root);
    	while(stack.size() != 0)
    	{
    		TreeNode* t = stack[stack.size() - 1];
    		stack.pop_back();
    		result.push_back(t->val);
    		if(t->right)
    		{
    			stack.push_back(t->right);
    		}
    		if(t->left)
    		{
    			stack.push_back(t->left);
    		}
    	}
    	return result;
    }
};