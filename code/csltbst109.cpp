#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* cur = head;
        int count = 0;
        while(cur)
        {
        	count++;
        	cur = cur->next;
        }
        if(count == 0)
        {
        	return NULL;
        }
        //cout << count << endl;
        vector<ListNode* > tmp;
        tmp.push_back(head);
        TreeNode *root = helper(tmp, 0, count - 1);
        return root;
    }
    
    TreeNode* helper(vector<ListNode*>& tmp, int l, int r)
    {
    	if(l > r)
    	{
    		return NULL;
    	}
    	int m = (l + r) / 2;
    	TreeNode *left = helper(tmp, l, m - 1);
    	ListNode *head = tmp[0];
    	tmp.pop_back();
    	TreeNode *root = new TreeNode(head->val);
    	//cout << root->val << endl;
    	tmp.push_back(head->next);
    	TreeNode *right = helper(tmp, m + 1, r);
    	root->left = left;
    	root->right = right;
    	return root;
    }
};

int main()
{
	ListNode l1 = ListNode(-10);
	ListNode l2 = ListNode(-3);
	ListNode l3 = ListNode(0);
	ListNode l4 = ListNode(5);
	ListNode l5 = ListNode(9);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	TreeNode *root = Solution().sortedListToBST(&l1);
	return 0;
}