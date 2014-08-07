#include <iostream>
#include <unordered_map>

struct RandomListNode
{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution
{
private:
    typedef std::unordered_map<int, RandomListNode*> um_t;
    
private:
    RandomListNode* copyImp(RandomListNode* head, um_t& um)
    {
        if (head == NULL)
        {
            return NULL;
        }
        um_t::iterator iter = um.find(head->label);
        if (iter != um.end())
        {
            return iter->second;
        }
        
        RandomListNode* p = new RandomListNode(head->label);
        um.insert(std::make_pair(p->label, p));
        p->next = copyImp(head->next, um);
        p->random = copyImp(head->random, um);
        return p;
    }
    
public:
    RandomListNode* copyRandomList(RandomListNode* head)
    {
        um_t um;
        return copyImp(head, um);
    }
};

int main(int argc, char **argv)
{
    Solution sln;
    
    return 0;
}

