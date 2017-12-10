#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* lp = l1;
        ListNode* rp = l2;
        ListNode h = ListNode(-1);
        ListNode* head = &h;
        ListNode* p = head;
        while(lp!=NULL && rp!=NULL)
        {
        	if(lp->val <= rp->val)
        	{
        		p->next = lp;
        		lp = lp->next;
        	}
        	else
        	{
        		p->next = rp;
        		rp = rp->next;
        	}
        	p = p->next;
        }
        if(rp!=NULL)
  		{
  			p->next = rp;
  		}
  		else
  		{
  			p->next = lp;
  		}
        return head->next;
    }
};

int main()
{
	ListNode l1 = ListNode(1);
	ListNode l11 = ListNode(2);
	ListNode l12 = ListNode(4);
	l1.next = &l11;
	l11.next = &l12;
	ListNode l2 = ListNode(1);
	ListNode l21 = ListNode(3);
	ListNode l22 = ListNode(4);
	l2.next = &l21;
	l21.next = &l22;
	ListNode* result;
	result = Solution().mergeTwoLists(&l1, &l2);
	while(result->next != NULL)
	{
		cout << result->val << endl;
	}
	return 0;
}