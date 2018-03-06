#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* p;
        ListNode* head;
       	int flag = 0;
        map<int, vector<ListNode*>> tmp;
        for(auto v : lists)
        {
        	if(v != NULL)
        	{
        		if(tmp.find(v->val) != tmp.end())
        		{
        			tmp[v->val].push_back(v);
        		}
        		else
        		{
        			vector<ListNode*> tmpv;
        			tmpv.push_back(v);
        			tmp[v->val] = tmpv;
        		}
        	}
        }
        if(tmp.empty())
        {
        	return NULL;
        }
        while(true)
        {
        	auto it = tmp.begin();
        	ListNode* q = *((it->second).end() - 1);
        	if(flag == 0)
        	{
        		head = q;
        		p = head;
        		flag = 1;
			}
			else
			{
				p->next = q;
				p = q;
			}
			(it->second).pop_back();
			if((it->second).size() == 0)
			{
				tmp.erase(q->val);
			}
			if(tmp.size() == 0)
			{
				break;
			}
			if(q->next != NULL)
			{
				ListNode* v = q->next;
				if(tmp.find(v->val) != tmp.end())
        		{
        			tmp[v->val].push_back(v);
        		}
        		else
        		{
        			vector<ListNode*> tmpv;
        			tmpv.push_back(v);
        			tmp[v->val] = tmpv;
        		}
			}

        }
        return head;
    }
};

int main()
{
	ListNode l11 = ListNode(1);
	ListNode l12 = ListNode(2);
	ListNode l13 = ListNode(10);
	ListNode l21 = ListNode(3);
	ListNode l22 = ListNode(4);
	ListNode l23 = ListNode(7);
	ListNode l31 = ListNode(2);
	ListNode l32 = ListNode(3);
	ListNode l33 = ListNode(11);
	ListNode l34 = ListNode(13);
	l11.next = &l12;
	l12.next = &l13;
	l21.next = &l22;
	l22.next = &l23;
	l31.next = &l32;
	l32.next = &l33;
	l33.next = &l34;
	vector<ListNode*> lists;
	lists.push_back(&l11);
	lists.push_back(&l21);
	lists.push_back(&l31);
	ListNode* head = Solution().mergeKLists(lists);
	while(head != NULL)
	{
		cout << head->val << endl;
		head = head->next;
	}
	return 0;
}