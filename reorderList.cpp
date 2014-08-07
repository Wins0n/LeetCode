#include <iostream>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
private:
    ListNode* partationList(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* temp = NULL;
        while (fast && fast->next)
        {
            temp = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        temp->next = NULL;
        return slow;
    }
    
    ListNode* reverseList(ListNode* head)
    {
        ListNode a(0);
        while (head)
        {
            ListNode* p = a.next;
            ListNode* q = head;
            head = head->next;
            a.next = q;
            q->next = p;
        }
        return a.next;
    }

    ListNode* mergeList(ListNode* pl, ListNode* pr)
    {
        ListNode a(0);
        ListNode *p = &a;
        while (pl && pr)
        {
            p->next = pl;
            p = p->next;
            pl = pl->next;
            p->next = pr;
            p = p->next;
            pr = pr->next;
        }
        if (pl)
        {
            p->next = pl;
        }
        if (pr)
        {
            p->next = pr;
        }
        return a.next;
    }
    
public:
    void reorderList(ListNode* head)
    {
        if (head && head->next)
        {
            ListNode* pr = partationList(head);
            ListNode* pl = head;
            pr = reverseList(pr);
            head = mergeList(pl, pr);
        }
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
    ListNode a(1), b(2), c(3), d(4);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    printList(&a);
    sln.reorderList(&a);
    printList(&a);
    
    return 0;
}

