#include <iostream>
#include <algorithm>
#include <vector>

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* e = head;
        ListNode* s;
        int count;
        int tmp;
        if(head == NULL)
        {
        	return head;
		}
        while(true)
        {
        	count = 1;
        	s = e;
        	while(e->next != NULL && e->val == e->next->val)
        	{
        		count++;
        		e = e->next;
        	}
        	if(count != 1)
        	{
        	
        		s->next = e->next;
        	}
        	e = e->next;
        	if(e == NULL)
        	{
        		break;
        	}
        }
        return head;
    }
};
int main()
{
	ListNode l1 = ListNode(1);
	ListNode l2 = ListNode(2);
	ListNode l3 = ListNode(2);
	l1.next = &l2;
	l2.next = &l3;
	ListNode *head = Solution().deleteDuplicates(&l1);
	while(head != NULL)
	{
		cout << head->val << endl;
		head = head -> next;
	}
	return 0;
}
