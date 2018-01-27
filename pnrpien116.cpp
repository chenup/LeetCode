#include <iostream>
#include <algorithm>

using namespace std;

struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };

class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* start = root;
        while(start)
        {
        	TreeLinkNode* p = start;
        	TreeLinkNode* tmp = NULL;
        	while(p)
        	{
        		if(!p->left)
        		{
        			break;
        		}
        		if(tmp)
        		{
        			tmp->next = p->left;
        		}
        		p->left->next = p->right;
        		tmp = p->right;
        		p = p->next;
        	}
        	start = start->left;
        }
    }
};

int main()
{
	TreeLinkNode l1 = TreeLinkNode(1);
	TreeLinkNode l2 = TreeLinkNode(2);
	TreeLinkNode l3 = TreeLinkNode(3);
	l1.left = &l2;
	l1.right = &l3;
	Solution().connect(&l1);
	return 0;
}