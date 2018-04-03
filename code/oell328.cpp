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
    ListNode* oddEvenList(ListNode* head) 
    {
   		int i = 1;
   		ListNode* odd_head = new ListNode(-1);
   		ListNode* even_head = new ListNode(-1);
   		ListNode* odd_tail = odd_head;
   		ListNode* even_tail = even_head;
   		while(head)
   		{
   			if(i % 2)
   			{
   				odd_tail->next = head;
   				odd_tail->next = odd_tail;
   				odd_tail->next = NULL;
   			}
   			else
   			{
   				even_tail->next = head;
   				even_tail->next = even_tail;
   				even_tail->next = NULL;
   			}
   			head = head->next;
   			i++;
   		}
   		odd_tail->next = even_head->next;
   		return odd_head->next;   
    }
};