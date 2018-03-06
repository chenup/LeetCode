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
    int minDepth(TreeNode* root) {
       vector<TreeNode*> queue;
       int top;
       if(root == NULL)
       {
       		return 0;
       }
       int deep = 0;
       queue.push_back(root);
       top = 0;
       int i = 0;
       vector<int> tmp;
       while(i <= top)
       {
       		tmp.push_back(queue[i]->val);
       		if(queue[i]->left == NULL && queue[i]->right == NULL)
       		{
       			return deep + 1;
       		}
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
       			deep++;
       			top = queue.end() - queue.begin() - 1;
       			tmp.clear();
       		}
       		i++;
       }
       return deep;
    }
};