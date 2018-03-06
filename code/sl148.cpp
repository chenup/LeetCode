#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode 
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
/*
class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
    	pair<ListNode*, ListNode*> result;
    	if(head == NULL)
    	{
    		return NULL;
		}
    	result = helper(head);
    	return result.first;	        
    }

    pair<ListNode*, ListNode*> helper(ListNode* head)
    {
    	pair<ListNode*, ListNode*> p_first;
    	pair<ListNode*, ListNode*> p_second;
    	ListNode* first = NULL;
    	ListNode* t_first = NULL;
    	ListNode* second = NULL;
    	ListNode* t_second = NULL;
    	ListNode* key;
    	key = head;
    	ListNode* p = head->next;
    	while(p)
    	{
    		if(p->val < key->val)
    		{
    			if(first == NULL)
    			{
    				first = p;
    				t_first = first;
    			}
    			else
    			{
    				t_first->next = p;
    				t_first = t_first->next;
    			}
    		}
    		else
    		{
    			if(second == NULL)
    			{
    				second = p;
    				t_second = second;
    			}
    			else
    			{
    				t_second->next = p;
    				t_second = t_second->next;
    			}
    		}
    		p = p->next;
    	}
    	if(first != NULL)
    	{
    		t_first->next = NULL;
    	}
    	if(second != NULL)
    	{
    		t_second->next = NULL;
    	}
    	pair<ListNode*, ListNode*> result;
    	if(first != NULL)
    	{
    		p_first = helper(first);
    		p_first.second->next = key;
    		if(second != NULL)
	    	{
	    		p_second = helper(second);
	    		key->next = p_second.first;
	    		result = make_pair(p_first.first, p_second.second);
	    	}
	    	else
	    	{
	    		key->next = NULL;
	    		result = make_pair(p_first.first, key);
	    	}
    	}
    	else
    	{
    		if(second != NULL)
	    	{
	    		p_second = helper(second);
	    		key->next = p_second.first;
	    		result = make_pair(key, p_second.second);
	    	}
	    	else
	    	{
	    		key->next = NULL;
	    		result = make_pair(key, key);
	    	}
    	}
    	return result;
    }
};
*/

class Solution {
public:
    ListNode* sortList(ListNode* head) {
    	ListNode *fast = head;
    	ListNode *slow = head;
    	ListNode *pre;
    	if(head == NULL || head->next == NULL)
    	{
    		return head;
    	}
    	while(fast && fast->next)
    	{
    		pre = slow;
    		slow = slow->next;
    		fast = fast->next->next;
    	}
    	pre->next = NULL;
    	return merge(sortList(head), sortList(slow));
    }

    ListNode* merge(ListNode* l1, ListNode* l2)
    {
    	if(l1 == NULL) return l2;
    	if(l2 == NULL) return l1;
    	if(l1->val < l2->val)
    	{
    		l1->next = merge(l1->next, l2);
    		return l1;
    	}
    	else
    	{
    		l2->next = merge(l1, l2->next);
    		return l2;
    	}
    }
};

int main(int argc, char const *argv[])
{
	ListNode l1 = ListNode(1);
	ListNode l2 = ListNode(1);
	ListNode l3 = ListNode(1);
	ListNode l4 = ListNode(1);
	ListNode l5 = ListNode(1);
	ListNode l6 = ListNode(1);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	ListNode* res = Solution().sortList(&l1);
	while(res)
	{
		cout << res->val << endl;
		res = res->next;
	}
	return 0;
}