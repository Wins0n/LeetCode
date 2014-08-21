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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int carry = 0;
        ListNode head(0);
        ListNode* p = &head;
        
        while (l1 && l2)
        {
            p->next = new ListNode(0);
            p = p->next;
            p->val = l1->val + l2->val + carry;
            if (p->val >= 10)
            {
                p->val -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode* q = l1;
        if (l2)
        {
            q = l2;
        }
        while (q)
        {
            p->next = new ListNode(0);
            p = p->next;
            p->val = q->val + carry;
            if (p->val >= 10)
            {
                p->val -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            q = q->next;
        }
        if (carry)
        {
            p->next = new ListNode(1);
        }
        
        return head.next;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    
    return 0;
}

