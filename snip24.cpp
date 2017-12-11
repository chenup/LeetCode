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
    ListNode* swapPairs(ListNode* head) {
        ListNode *p, *q, *tmp;
        p = head;
        if(head != NULL && head->next != NULL)
        {
        	head = head->next;
        }
        while(p != NULL)
        {
        	if(p->next != NULL)
        	{
	        	tmp = p->next->next;
	        	p->next->next = p;
	        	if(tmp != NULL)
	        	{
	        		if(tmp->next != NULL)
	        		{
	        			p->next = tmp->next;
	        		}
	        		else
	        		{
	        			p->next = tmp;
	        		}
	        		
	        	}
	        	else
				{
					p->next = NULL;	
				}
	        	p = tmp;
	        }
	        else
	        {
	        	p = p->next;
	        }
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
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	ListNode* head = Solution().swapPairs(&l1);
	while(head != NULL)
	{
		cout << head->val << endl;
		head = head->next;
	}
	return 0;
}