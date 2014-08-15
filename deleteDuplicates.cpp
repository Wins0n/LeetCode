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

        ListNode* cur = head->next;
        ListNode* pre = head;
        while (cur)
        {
            if (cur->val == pre->val)
            {
                pre->next = cur->next;
            }
            else
            {
                pre = cur;
            }
            cur = cur->next;
        }
        return head;
    }
};

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
    while (p)
    {
        std::cout << p->val << " -> ";
        p = p->next;
    }
    std::cout << "NULL" << std::endl;
    
    return 0;
}

