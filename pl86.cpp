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
    ListNode* partition(ListNode* head, int x) {
        ListNode* pre, pos;
        pos = head;
        pre = head;
        while(pos != NULL)	
        {
        	if(pos->val < x)
        	{
        		if(pre == pos)
        		{
        			pos = pos->next;
        			pre = pre->next;
        		}
        		else
        		{
        			ListNode* next;
        			ListNode* tmp = pos->next;
        			if(pre == head && pre->val >= x)
        			{
        				next = head;
        				head = pos;
        			}
        			else
        			{
        				next = pre->next;
        				pre->next = pos;
        			}
        			pos->next = next;
        			pre = pos;
        			pos = tmp;
        		}
        	}
        	else
        	{
        		pos = pos->next;
        	}
        }
        return
    }
};

int main()
{
	ListNode l1 = ListNode(1);
	ListNode l2 = ListNode(4);
	ListNode l3 = ListNode(3);
	ListNode l4 = ListNode(2);
	ListNode l5 = ListNode(5);
	ListNode l6 = ListNode(2);
	int x = 3;
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	ListNode* head = Solution().partition(&l1, x);
	while(head != NULL)
	{
		cout << head->val;
		head = head->next;
	}
	return 0;
}