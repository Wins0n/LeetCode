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
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        ListNode a(0);
        a.next = head;
        
        ListNode* pre = &a;
        ListNode* cur = pre->next;
        for (int i = 1; i < m; ++i)
        {
            pre = cur;
            cur = cur->next;
        }

        ListNode b(0);
        ListNode* q = cur;
        for (int i = 0; i < (n-m+1); ++i)
        {
            ListNode* p = cur->next;
            cur->next = b.next;
            b.next = cur;
            cur = p;
        }
        
        pre->next = b.next;
        q->next = cur;
        return a.next;
    }
};

void printList(ListNode* p)
{
    while (p)
    {
        std::cout << p->val << "->";
        p = p->next;
    }
    std::cout << "NULL" << std::endl;
}

int main(int argc, char** argv)
{
    Solution sln;
    ListNode a[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5-1; ++i)
    {
        a[i].next = &a[i+1];
    }
    printList(&a[0]);
    ListNode* p = sln.reverseBetween(&a[0], 2, 4);
    printList(p);
    
    return 0;
}

