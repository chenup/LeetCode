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
    bool hasCycle(ListNode *head) {
    	set<ListNode*> visited;
        ListNode *p = head;
        while(p)
        {
        	if(visited.find(p) != visited.end())
        	{
        		return true;
        	}
        	visited.insert(p);
        	p = p->next;
        }
        return false;
    }
};