#include <iostream>

struct RandomListNode
{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution
{
public:
    RandomListNode* copyRandomList(RandomListNode* head)
    {
        if (head)
        {
            RandomListNode* p = head;
            RandomListNode* q = NULL;
            while (p)
            {
                q = new RandomListNode(p->label);
                q->next = p->next;
                p->next = q;
                p = p->next->next;
            }
            p = head;
            while (p)
            {
                if (p->random)
                {
                    p->next->random = p->random->next;
                }
                p = p->next->next;
            }
            p = head;
            head = head->next;
            while (true)
            {
                q = p->next;
                p->next = q->next;
                if (p->next)
                {
                    q->next = q->next->next;
                }
                else
                {
                    break;
                }
                p = p->next;
            }
        }
        return head;
    }
};

int main(int argc, char **argv)
{
    Solution sln;
    RandomListNode node(-1);
    RandomListNode* p = sln.copyRandomList(&node);
    
    return 0;
}

