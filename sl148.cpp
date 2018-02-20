#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode 
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
    	pair<ListNode*, ListNode*> result;
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
    	if(head == NULL)
    	{
    		return make_pair(NULL, NULL);
    	}
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

int main(int argc, char const *argv[])
{
	ListNode l1 = ListNode(4);
	ListNode l2 = ListNode(2);
	ListNode l3 = ListNode(5);
	ListNode l4 = ListNode(3);
	ListNode l5 = ListNode(1);
	ListNode l6 = ListNode(7);
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