#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *pre, *pos, *p, *next;
        pos = head;
        if(m == n)
        {
        	return head;
        }
        if(m == 1)
        {
        	p = pos;
        	pos = pos->next;
        	pre = p;
        	int i = 2;
        	while(i < n)
        	{
        		next = pos->next;
        		pos->next = p;
        		p = pos;
        		pos = next;
        		i++;
        	}
        	pre->next = pos->next;
        	pos->next = p;
        	head = pos;
        }
        else
        {
        	int i = 1;
        	while(i < m - 1)
        	{
        		pos = pos->next;
        		i++;
        	}
        	pre = pos;
        	p = pos->next;
        	pos = pos->next->next;
        	i = m + 1;
        	while(i < n)
        	{
        		next = pos->next;
        		pos->next = p;
        		p = pos;
        		pos = next;
        		i++;
        	}
        	pre->next->next = pos->next;
        	pos->next = p;
        	pre->next = pos;
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
	int m = 1;
	int n = 4;
	ListNode* head = Solution().reverseBetween(&l1, m, n);
	while(head != NULL)
	{
		cout << head->val << endl;
		head = head->next;
	}
	return 0;
}