class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
  		ListNode *p = head;
  		set<ListNode*> table;
  		while(p)
  		{
  			if(table.find(p) != table.end())
  			{
  				return p;
  			}
  			else
  			{
  				table.insert(p);
  				
  			}
  			p = p->next;
  		}      
  		return NULL;
    }
};