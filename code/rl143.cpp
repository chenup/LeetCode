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
    void reorderList(ListNode* head) 
    {
    	ListNode* slow_p;
    	ListNode* fast_p;
    	ListNode* second;
    	ListNode* tail;
    	if(head == NULL || head->next == NULL || head->next->next == NULL)
    	{
    		return;
    	}
    	slow_p = head;
    	fast_p = head;
    	while(true)
    	{
    		fast_p = fast_p->next->next;
    		if(!fast_p)
    		{
    			second = slow_p->next;
    			slow_p->next = NULL;
    			second = reverse(second);
    			break;
    		}
    		if(!fast_p->next)
    		{
    			second = slow_p->next->next;
    			slow_p->next->next = NULL;
    			second = reverse(second);
    			break;
    		}
    		slow_p = slow_p->next;
    	}
    	ListNode* p = head;
    	ListNode* q = second;
    	while(true)
    	{
    		if(!p || !q)
    		{
    			return;
    		}
    		ListNode* tmp = p->next;
    		p->next = q;
    		p = tmp;
    		tmp = q->next;
    		q->next = p;
    		q = tmp;
    	}	
    }

    ListNode* reverse(ListNode* head)
    {
    	ListNode* p = head;
    	ListNode* result;
    	while(p->next)
    	{
    		p = p->next;
    	}
    	result = p;
    	ListNode* q = head;
    	while(q != result)
    	{
    		p = result->next;
    		result->next = q;
    		q = q->next;
 			result->next->next = p;
    	}
    	return result;
    }
};

int main()
{
	ListNode l1 = ListNode(1);
	ListNode l2 = ListNode(2);
	ListNode l3 = ListNode(3);
	ListNode l4 = ListNode(4);
	ListNode l5 = ListNode(5);
	ListNode l6 = ListNode(6);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	Solution().reorderList(&l1);
	ListNode *p = &l1;
	while(p)
	{
		cout << p->val << endl;
		p = p->next;
	}
	return 0;
}