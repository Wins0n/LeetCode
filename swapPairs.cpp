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
    ListNode* swapPairs(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode a(0);
        ListNode* pre = head;
        ListNode* post = pre->next;
        ListNode* tmp = &a;
        while (true)
        {
            tmp->next = post;
            pre->next = post->next;
            post->next = pre;
            tmp = pre;
            pre = pre->next;
            if (pre == NULL)
            {
                break;
            }
            post = pre->next;
            if (post == NULL)
            {
                break;
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
    const int n = 4;
    ListNode a[n] = {1, 2, 3, 4};
    for (int i = 0; i < n-1; ++i)
    {
        a[i].next = &a[i+1];
    }

    printList(&a[0]);
    ListNode* p = sln.swapPairs(&a[0]);
    printList(p);

    return 0;
}

