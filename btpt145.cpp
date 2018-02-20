class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
		vector<TreeNode*> stack;
		set<TreeNode*> visited;
		vector<int> result;
		if(root == NULL)
		{
			return result;
		}
		stack.push_back(root);
		while(stack.size() != 0)
		{
			TreeNode* t = stack[stack.size() - 1];
			if(visited.find(t) != visited.end())
			{
				result.push_back(t->val);
				stack.pop_back();
				continue;
			}
			if(t->right != NULL)
			{
				stack.push_back(t->right);
			}
			if(t->left != NULL)
			{
				stack.push_back(t->left);
			}
			visited.insert(t);
		}
		return result;
    }
};