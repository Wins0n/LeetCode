#include <iostream>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* partition(ListNode* head, int x)
    {
        ListNode lt(0);
        ListNode gt(0);
        ListNode* q = &gt;
        ListNode* cur = head;
        ListNode* pre = &lt;
        
        while (cur)
        {
            if (cur->val < x)
            {
                pre->next = cur;
                pre = cur;
            }
            else
            {
                q->next = cur;
                q = q->next;
                pre->next = cur->next;
            }
            cur = cur->next;
        }
        q->next = NULL;
        pre->next = gt.next;
        return lt.next;
    }
};

void printList(ListNode* p)
{
    while (p)
    {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    const int n = 6;
    Solution sln;
    ListNode node[n] = {1, 4, 3, 2, 5, 2};
    for (int i = 0; i < n-1; ++i)
    {
        node[i].next = &node[i+1];
    }
    printList(&node[0]);
    ListNode* p = sln.partition(&node[0], 3);
    printList(p);
    
    return 0;
}
