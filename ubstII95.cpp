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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        if(n == 0)
        {
            return result;
        }
        result = helper(result, 1, n);
       	return result;
    }

    vector<TreeNode*> helper(int start, int end)
    {
        vector<TreeNode*> tmp;
        if(start > end)
        {
            tmp.push_back(NULL);
        }
        for(int k = start; k <= end; k++)
        {
            vector<TreeNode*> leftv = helper(start, k - 1);
            vector<TreeNode*> rightv = helper(k + 1, end);
            for(auto left : leftv)
            {
                for(auto right : rightv)
                {
                    TreeNode* root = new TreeNode(k);
                    root->left = left;
                    root->right = right;
                    tmp.push_back(root);
                }
            }
        }
    }
    return tmp;

};

int main()
{
	int n = 3;
	vector<TreeNode*> result = Solution().generateTrees(n);
	return 0;
}