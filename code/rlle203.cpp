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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* res = new ListNode(-1);
        res->next = head;
        ListNode* pre = res;
        ListNode* pos = head;
        while(pos)
        {
        	if(pos->val == val)
        	{
        		pre->next = pos->next;
        		pos = pos->next;
        	}
        	else
        	{
        		pre = pre->next;
        		pos = pos->next;
        	}
        }
    return res->next;
    }
};