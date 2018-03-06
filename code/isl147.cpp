#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode* insertionSortList(ListNode* head) 
    {
    	ListNode* p = head;
    	ListNode* q;
    	head = NULL;
    	while(p)
    	{
    		q = head;
    		if(head)
    		{
    			ListNode* tmp = NULL;
    			while(q)
    			{

    				if(p->val >= q->val)
    				{
    					tmp = q;
    				}
    				else
    				{
    					if(tmp == NULL)
    					{
    						tmp = p;
    						p = p->next;
    						tmp->next = q;
    						head = tmp;
    					}
    					else
    					{
    						ListNode* l;
    						tmp->next = p;
    						l = p;
    						p = p->next;
    						l->next = q;
    					}
    					break;
    				}
    				q = q->next;
    			}
    			if(q == NULL)
    			{
    				tmp->next = p;
    				p = p->next;
    				tmp->next->next = NULL;
    			}
    		}
    		else
    		{
    			head = p;
    			p = p->next;
    			head->next = NULL;
    			
    		}
    		
    	}
    	return head; 
    }
};

int main()
{
	ListNode l1 = ListNode(1);
	ListNode l2 = ListNode(3);
	ListNode l3 = ListNode(2);
	ListNode l4 = ListNode(4);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	ListNode* head = Solution().insertionSortList(&l1);
	while(head)
	{
		cout << head->val << endl;
		head = head->next;
	}
	return 0;
}