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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1 || head == NULL)
        {
        	return head;
        }
        ListNode *pre, *next, *p, *s, *e;
        p = head;
        bool flag = false;
        while(true)
        {
        	int i;
        	for(i = 1; i <= k; i++)
        	{
        		if(p == NULL)
        		{
        			break;
        		}
        		p = p->next;
        	}
        	if(i <= k)
        	{
        		break;
        	}
        	next = p;
        	if(!flag)
        	{
        		p = head;
        	}
        	else
        	{
        		p = pre->next;
        	}
        	for(i = 1; i <= k; i++)
        	{
        		e = p->next;
        		if(i == 1)
        		{
        			p->next = next;		
        		}
        		else if(i == k)
        		{
        			p->next = s;
        			if(!flag)
        			{
        				pre = head;
        				head = p;
        			}
        			else
        			{
        				ListNode* tmp;
	        			tmp = pre->next;
	        			pre->next = p;
	        			pre = tmp;
        			}
        			
        		}
        		else
        		{
        			p->next = s;
        		}
        		s = p;
        		p = e;
        	}	
        	flag = true;
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
	int k = 2;
	ListNode* head = Solution().reverseKGroup(&l1, k);
	while(head != NULL)
	{
		cout << head->val << endl;
		head = head->next;
	}
	return 0;

}

