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
    ListNode* insertionSortList(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode a(0);
        ListNode* p = head->next;
        a.next = head;
        head->next = NULL;
        
        while (p)
        {
            ListNode* pre = &a;
            ListNode* cur = pre->next;
            ListNode* tmp = NULL;
            while (cur && p->val > cur->val)
            {
                pre = cur;
                cur = cur->next;
            }
            tmp = p->next;
            pre->next = p;
            p->next = cur;
            p = tmp;
        }
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

int main(int argc, char **argv)
{
    Solution sln;
    ListNode a(5), b(4), c(8), d(1);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    printList(&a);
    ListNode* p = sln.insertionSortList(&a);
    printList(p);
    
    return 0;
}

