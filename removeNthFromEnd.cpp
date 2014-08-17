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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (head == NULL)
        {
            return NULL;
        }
        
        ListNode* p = head;
        ListNode a(0);
        a.next = head;
        ListNode* q = &a;
        
        for (int i = 0; i < n; ++i)
        {
            p = p->next;
        }
        while (p)
        {
            p = p->next;
            q = q->next;
        }
        q->next = q->next->next;
        return a.next;
    }
};

void printList(ListNode* p)
{
    while (p)
    {
        std::cout << p->val << " -> ";
        p = p->next;
    }
    std::cout << "NULL" << std::endl;
}

int main(int argc, char** argv)
{
    Solution sln;
    const int n = 5;
    ListNode a[n] = {1, 2, 3, 4, 5};
    for (int i = 0; i < n-1; ++i)
    {
        a[i].next = &a[i+1];
    }
    printList(&a[0]);
    ListNode* p = sln.removeNthFromEnd(&a[0], 2);
    printList(p);

    return 0;
}

