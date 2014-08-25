#include <iostream>
#include <vector>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    int getLength(ListNode* p)
    {
        int res = 0;
        while (p)
        {
            p = p->next;
            ++res;
        }
        return res;
    }
    
    TreeNode* imp(ListNode* head, int n)
    {
        if (n == 0)
        {
            return NULL;
        }
        if (n == 1)
        {
            return new TreeNode(head->val);
        }
        
        ListNode* cur = head;
        ListNode* pre = cur;
        int m = n/2;
        while (m--)
        {
            pre = cur;
            cur = cur->next;
        }
        pre->next = NULL;
        
        TreeNode* p = new TreeNode(cur->val);
        p->left = imp(head, n/2);
        p->right = imp(cur->next, n-n/2-1);
        return p;
    }

public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        return imp(head, getLength(head));
    }
};

int main(int argc, char** argv)
{
    Solution sln;

    return 0;
}

