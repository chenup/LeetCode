#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;




  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
        	return true;
        }
        ListNode *fast, *slow;
        ListNode *pre;
        fast = head;
        slow = head;
        while(fast != NULL && fast->next != NULL)
        {
        	fast = fast->next->next;
            pre = slow;
        	slow = slow->next;
        }
        pre->next = NULL;
        ListNode* tail = slow;
        while(tail->next != NULL)
        {
        	tail = tail->next;
        }
        while(slow != tail)
        {
        	ListNode* tmp = tail->next;
        	tail->next = slow;
        	slow = slow->next;
        	tail->next->next = tmp;
        	
        }
        while(head && tail)
        {
        	if(head->val != tail->val)
        	{
        		return false;
        	}
        	head = head->next;
        	tail = tail->next;
        }
        return true;
    }	
};
int main()
{
	ListNode l1 = ListNode(0);
	ListNode l2 = ListNode(1);
	ListNode l3 = ListNode(0);
	l1.next = &l2;
	l2.next = &l3;
	cout << Solution().isPalindrome(&l1); 
	return 0;
}