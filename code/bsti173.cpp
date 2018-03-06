#include <iostream>
#include <algorithm>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        if(root == NULL)
        {
        	index = -1;
        }
        else
        {
        	index = 0;
        	helper(root, queue);
        }
    }

    void helper(TreeNode* root, vector<int>& queue)
    {
    	if(root == NULL)
    	{
    		return;
    	}
    	helper(root->left, queue);
    	queue.push_back(root->val);
    	helper(root->right, queue);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(index == -1 || index == queue.size())
        {
        	return false;
        }
        else
        {
        	return true;
        }
    }

    /** @return the next smallest number */
    int next() {
        return queue[index++];
    }

private:
vector<int> queue;
int index;
};

int main()
{
	TreeNode* root = new TreeNode(1);
	BSTIterator i = BSTIterator(root);
	while (i.hasNext()) cout << i.next();
}

