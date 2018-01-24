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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<TreeNode*> queue;
       int top;
       bool flag = false;
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
            if(flag)
            {
              vector<int> vec;
              for(auto it = tmp.end() - 1; it >= tmp.begin(); it--)
              {
                vec.push_back(*it);
              }
              result.push_back(vec);
            }
            else
            {
              result.push_back(tmp);
            }
       			
       			top = queue.end() - queue.begin() - 1;
       			tmp.clear();
            flag = !flag;
       		}
       		i++;
       }
       return result;
    }
};

int main(int argc, char const *argv[])
{
	
	return 0;
}