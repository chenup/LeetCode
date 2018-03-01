class Solution 
{
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
   		vector<ListNode*> graph(numCourses, NULL);
   		vector<int> marked(numCourses, false);
   		vector<int> onStack(numCourses, false);
   		vector<int> empty;
   		for(auto it : prerequisites)
   		{
   			int v = it.first;
   			int w = it.second;
   			ListNode* p = new ListNode(w);
   			if(graph[v] == NULL)
   			{
   				graph[v] = p;
   			}
   			else
   			{
   				ListNode* tmp = graph[v];
   				graph[v] = p;
   				p->next = tmp; 
   			}
   		}
   		for(int i = 0; i < numCourses; i++)
   		{
   			if(!marked[i])
   			{
   				if(dfs(graph, marked, onStack, i))
   				{
   					return empty;
   				}
   			}
   		}
   		return post;
    }

    bool dfs(vector<ListNode*>& graph, vector<int>& marked, vector<int>& onStack, int v)
    {
    	marked[v] = true;
    	onStack[v] = true;	
    	ListNode* head = graph[v];
    	while(head != NULL)
    	{
    		int w = head->val;
    		if(onStack[w])
    		{
    			return true;
    		}
    		else
    		{
    			if(!marked[w] && dfs(graph, marked, onStack, w))
    			{
    				return true;
    			}
    		}
    		head = head->next;
    	}
    	onStack[v] = false;
    	post.push_back(v);
    	return false;
    }
private:
	vector<int> post;
};