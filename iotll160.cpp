/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode* p = headA;
        ListNode* q = headB;
        while(p)
        {
        	lenA++;
        	p = p->next;
        }
        while(q)
        {
        	lenB++;
        	q = q->next;
        }
        if(lenA < lenB)
        {
        	int n = lenB - lenA;
        	p = headA;
        	q = headB;
        	for(int i = 1; i <= n; i++)
        	{
        		q = q->next;
        	}
        	while(p)
        	{
        		if(p == q)
        		{
        			return p;
        		}
        		p = p->next;
        		q = q->next;
        	}
        }
        else
        {
        	int n = lenA - lenB;
        	p = headA;
        	q = headB;
        	for(int i = 1; i <= n; i++)
        	{
        		p = p->next;
        	}
        	while(p)
        	{
        		if(p == q)
        		{
        			return p;
        		}
        		p = p->next;
        		q = q->next;
        	}
        }
        return NULL;
    }
};