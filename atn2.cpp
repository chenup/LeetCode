#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = l1;
		ListNode* tmp = l2;
		int c = 0;
		int val;
		val = l1->val + l2->val;
		c = val / 10;
		val = val % 10;
		l1->val = val;
		while (l1->next != NULL&&l2->next != NULL)
		{
			l1 = l1->next;
			l2 = l2->next;
			val = l1->val + l2->val + c;
			c = val / 10;
			val = val % 10;
			l1->val = val;
		}
		if (l1->next == NULL)
		{
			l1->next = l2->next;
		}
		while (l1->next != NULL)
		{
			l1 = l1->next;
			val = l1->val + c;
			c = val / 10;
			val = val % 10;
			l1->val = val;
			if (c == 0)
			{
				break;
			}
		}
		if (c > 0)
		{
			tmp->val = c;
			tmp->next = NULL;
			l1->next = tmp;
		}
		return head;
	}
};

int main()
{
	ListNode l1 = ListNode(5);
	ListNode l2 = ListNode(5);
	Solution().addTwoNumbers(&l1, &l2);
	return 0;
}