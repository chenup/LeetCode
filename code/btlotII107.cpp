
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
       vector<TreeNode*> queue;
       int top;
       vector<vector<int>> result;
       if(root == NULL)
       {
       		return result;
       }
       queue.push_back(root);
       top = 0;
       int i = 0;
       vector<int> tmp;
       while(i <= top)
       {
       		tmp.push_back(queue[i]->val);
       		if(queue[i]->left != NULL)
       		{
       			queue.push_back(queue[i]->left);
       		}
       		if(queue[i]->right != NULL)
       		{
       			queue.push_back(queue[i]->right);
       		}
       		if(i == top)
       		{
       			result.push_back(tmp);
       			top = queue.end() - queue.begin() - 1;
       			tmp.clear();
       		}
       		i++;
       }
       reverse(result.begin(), result.end());
       return result;
    }
};