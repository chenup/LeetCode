/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
        {
        	return NULL;
        }
        map<RandomListNode*, RandomListNode*> queue;
        RandomListNode* new_head = new RandomListNode(head->label);
        queue[head] = new_head;
        RandomListNode *p = head;
        while(p != NULL)
        {
        	if(p->random != NULL)
        	{
        		if(queue.find(p->random) != queue.end())
        		{
        			queue[p]->random = queue[p->random];
        		}
        		else
        		{
        			RandomListNode* tmp = new RandomListNode(p->random->label);
        			queue[p->random] = tmp;
        			queue[p]->random = tmp; 
        		}
        	}
        	if(p->next != NULL)
        	{
        		if(queue.find(p->next) != queue.end())
        		{
        			queue[p]->next = queue[p->next];
        		}
        		else
        		{
        			RandomListNode* tmp = new RandomListNode(p->next->label);
        			queue[p->next] = tmp;
        			queue[p]->next = tmp; 
        		}
        	}
        	p = p->next;
        }
        return new_head;
    }
};