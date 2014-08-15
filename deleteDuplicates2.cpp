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
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode a(0);
        ListNode* pre = &a;
        ListNode* cur = head;
        a.next = head;
        while (cur && cur->next)
        {
            if (cur->val == cur->next->val)
            {
                int val = cur->val;
                while (cur && cur->val == val)
                {
                    cur = cur->next;
                }
                pre->next = cur;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
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

int main(int argc, char** argv)
{
    Solution sln;
    const int num = 7;
    ListNode a[num] = {1, 2, 3, 3, 4, 4, 5};
    for (int i = 0; i < num-1; ++i)
    {
        a[i].next = &a[i+1];
    }
    ListNode* p = sln.deleteDuplicates(&a[0]);
    printList(p);
    
    return 0;
}

