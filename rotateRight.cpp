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
    int getLength(ListNode* p)
    {
        int n = 0;
        while (p)
        {
            ++n;
            p = p->next;
        }
        return n;
    }
    
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        int n = getLength(head);
        if (n == 0 || n == 1)
        {
            return head;
        }
        
        k %= n;
        if (k == 0)
        {
            return head;
        }
        
        int l = n - k;
        ListNode* p = head;
        for (int i = 0; i < l-1; ++i)
        {
            p = p->next;
        }
        ListNode* q = p->next;
        p->next = NULL;
        p = q;
        while (p->next)
        {
            p = p->next;
        }
        p->next = head;
        return q;
    }
};

void printList(ListNode* p)
{
    while(p)
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
    ListNode* p = sln.rotateRight(&a[0], 2);
    printList(p);
    
    return 0;
}

