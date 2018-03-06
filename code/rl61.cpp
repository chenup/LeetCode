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
    ListNode* rotateRight(ListNode* head, int k) {
    	/*
        ListNode *p = head;
        ListNode *m = p;
        int l = 0;
        if(head == NULL)
        {
        	return NULL;
        }
        while(p != NULL && k)
        {
        	m = p;
        	p = p->next;
        	k--;
        	l++;
        }
        if(k == 0)
        {
        	if(p == NULL)
        	{
        		return head;
        	}
        	else
        	{
        		ListNode *q = p;
        		while(q->next != NULL)
        		{
        			q = q->next;
        		}
        		q->next = head;
        		m->next = NULL;
        		return p;
        	}
        }
        if(p == NULL)
        {
        	int idx = k % l;
        	if(idx == 0)
        	{
        		return head;
        	}
        	m->next = head;
        	for(int i = idx; i >= 2; i--)
        	{
        		head = head->next;
        	}
        	p = head->next;
        	head->next = NULL;
        	return p;
        }
        return NULL;
        */
        ListNode *p = head;
        ListNode *m;
        int l = 0;
        if(head == NULL)
        {
        	return head;
        }
        while(p != NULL)
        {
        	l++;
        	m = p;
        	p = p->next;
        }
        int i = k % l;
        if(i == 0)
        {
        	i = l;
        }
        int idx = l - i;
        if(idx == 0)
        {
        	return head;
        }
        p = head;
        for(int j = 2; j <= idx; j++)
        {
        	p = p->next;
        }
        m->next = head;
        m = p->next;
        p->next = NULL;
        return m;
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
	ListNode *head = &l1;
	int k = 2;
	ListNode *result = Solution().rotateRight(head, k);
	while(result != NULL)
	{
		cout << result->val;
		result = result->next;
	}
	return 0;
}