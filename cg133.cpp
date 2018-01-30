/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        vector<UndirectedGraphNode* > visited;
        vector<UndirectedGraphNode* > clone_visited;
        if(node == NULL)
        {
            return NULL;
        }
        UndirectedGraphNode* tmp = new UndirectedGraphNode(node->label);
        clone_visited.push_back(tmp);
        visited.push_back(node);
        int n = 0;
        UndirectedGraphNode *p;
        UndirectedGraphNode *c;
        while(visited.begin() + n != visited.end())
        {
            p = visited[n];
            c = clone_visited[n];
            for(auto it : p->neighbors)
            {
                auto itt = find(visited.begin(), visited.end(), it);
                if(itt != visited.end())
                {
                    int idx = itt - visited.begin();
                    (c->neighbors).push_back(clone_visited[idx]);
                }
                else
                {
                    UndirectedGraphNode* q = new UndirectedGraphNode(it->label);
                    (c->neighbors).push_back(q);
                    clone_visited.push_back(q);
                    visited.push_back(it);
                }
            }
            n++;
        }
        return clone_visited[0];
    }
};