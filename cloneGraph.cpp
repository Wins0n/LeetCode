#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

struct UndirectedGraphNode
{
    int label;
    std::vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int x) : label(x) {}
};

class Solution
{
public:
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node)
    {
        if (NULL == node)
        {
            return NULL;
        }
        
        std::queue<UndirectedGraphNode*> q;
        std::unordered_map<int, UndirectedGraphNode*> um;
        UndirectedGraphNode* head = new UndirectedGraphNode(node->label);
        UndirectedGraphNode* tmp = NULL;
        q.push(node);
        um.insert(std::make_pair(head->label, head));
        
        while (!q.empty())
        {
            UndirectedGraphNode* cur = q.front();
            q.pop();
            std::unordered_map<int, UndirectedGraphNode*>::iterator um_iter = um.find(cur->label);
            if (um_iter == um.end())
            {
                tmp = new UndirectedGraphNode(cur->label);
                um.insert(std::make_pair(tmp->label, tmp));
            }
            else
            {
                tmp = um_iter->second;
            }
            
            for(std::vector<UndirectedGraphNode*>::iterator iter = cur->neighbors.begin();
                iter != cur->neighbors.end();
                ++iter)
            {
                UndirectedGraphNode* clone = NULL;
                um_iter = um.find((*iter)->label);
                if (um_iter == um.end())
                {
                    clone = new UndirectedGraphNode((*iter)->label);
                    um.insert(std::make_pair(clone->label, clone));
                    q.push(*iter);
                }
                else
                {
                    clone = um_iter->second;
                }
                tmp->neighbors.push_back(clone);
            }
        }
        return head;
    }
};

int main(int argc, char **argv)
{
    Solution sln;
    
    return 0;
}

