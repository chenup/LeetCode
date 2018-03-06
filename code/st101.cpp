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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
        {
        	return true;
        }
        return isSameTree(root->left, root->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
        {
        	return true;
        }
        else if(p == NULL || q == NULL)
        {
        	return false;
        }
        if(p->val != q->val)
        {
        	return false;
        }
        if(!isSameTree(p->left, q->right) || !isSameTree(p->right, q->left))
        {
        	return false;
        }
        return true;
    }
};
