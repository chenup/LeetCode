#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        vector<TreeNode*> visit;
        vector<TreeNode*> stack;
        if(root == NULL)
        {
        	return result;
		}
        stack.push_back(root);
        int top = 0;
        while(top >= 0)
        {
        	if(stack[top]->left != NULL && find(visit.begin(), visit.end(), stack[top]->left) == visit.end())
        	{
        		stack.push_back(stack[top]->left);
        		top++; 
        	}
        	else
        	{
        		TreeNode* tmp = stack[top];
        		//cout << tmp->val << endl;
        		visit.push_back(tmp);
        		result.push_back(tmp->val);
        		stack.pop_back();
        		top--;
        		if(tmp->right != NULL)
        		{
        			stack.push_back(tmp->right);
        			top++;
        		}
        	}
        }
        return result;
    }
};

int main()
{
	TreeNode root = TreeNode(1);
	TreeNode l2 = TreeNode(2);
	TreeNode l3 = TreeNode(3);
	root.right = &l2;
	l2.left = &l3;
	vector<int> result = Solution().inorderTraversal(&root);
	for(auto v : result)
	{
		cout << v << endl;
	}
	return 0;
}