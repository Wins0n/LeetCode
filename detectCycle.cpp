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
    ListNode* detectCycle(ListNode* head)
    {
        bool hasCycle = false;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                hasCycle = true;
                break;
            }
        }
        if (!hasCycle)
        {
            return NULL;
        }
        
        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};

int main(int argc, char **argv)
{
    Solution sln;

    return 0;
}

