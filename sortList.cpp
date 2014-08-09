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
        int size = 0;
        while (p)
        {
            p = p->next;
            ++size;
        }
        return size;
    }

    ListNode* mergeList(ListNode* pl, ListNode* pr)
    {
        ListNode head(0);
        ListNode* p = &head;
        
        while (pl && pr)
        {
            if (pl->val < pr->val)
            {
                p->next = pl;
                pl = pl->next;
            }
            else
            {
                p->next = pr;
                pr = pr->next;
            }
            p = p->next;
        }
        
        if (pl)
        {
            p->next = pl;
        }
        else
        {
            p->next = pr;
        }
        return head.next;
    }
    
public:
    ListNode* sortList(ListNode* head)
    {
        int n = getLength(head);
        if (n == 0 || n == 1)
        {
            return head;
        }
        n /= 2;
        ListNode* pl = head;
        ListNode* pr = head;
        while (n)
        {
            --n;
            pl = pr;
            pr = pr->next;
        }
        pl->next = NULL;
        pl = sortList(head);
        pr = sortList(pr);
        head = mergeList(pl, pr);
        return head;
    }
};

int main(int argc, char **argv)
{
    return 0;
}

