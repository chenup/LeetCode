#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        ListNode* q = p;
        ListNode* m = p;
        if(n == 0)
        {
        	return head;
        }
        for(int i = 1; i <= n; i++)
        {
        	q = q->next;
        }
        while(q != NULL)
        {
        	m = p;
        	p = p->next;
        	q = q->next;
        }
        if(m == p)
        {
        	return head->next;
        }
        else
        {
        	m->next = p->next;
        }
        return head;
    }
};

int main()
{
	ListNode l1 = ListNode(1);
	ListNode l2 = ListNode(2);
	ListNode l3 = ListNode(3);
	ListNode l4 = ListNode(4);
	ListNode l5 = ListNode(5);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	int n = 1;
	ListNode* head = Solution().removeNthFromEnd(&l1, n);
	while(head != NULL)
	{
		cout << head->val << endl;
		head = head->next;
	}
}