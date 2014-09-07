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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode a(0), b(0);
        ListNode* preTail = &a;
        ListNode* tmpHead = &b;;
        ListNode* cur = head;
        ListNode* pre = &a;
        ListNode* curTail = NULL;
        
        int i = 0;
        while (cur)
        {
            ListNode* p = cur->next;
            cur->next = tmpHead->next;
            tmpHead->next = cur;
            pre = cur;
            cur = p;
            ++i;
            if (i == 1)
            {
                curTail = pre;
            }
            if (i == k)
            {
                i = 0;
                preTail->next = tmpHead->next;
                preTail = curTail;
                tmpHead = &b;
                b.next = NULL;
            }
        }
        if (i != k)
        {
            cur = tmpHead->next;
            while (cur)
            {
                ListNode* p = cur->next;
                cur->next = preTail->next;
                preTail->next =  cur;
                cur = p;
            }
        }
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
    ListNode* p = sln.reverseKGroup(&a[0], 3);
    printList(p);
    
    return 0;
}

