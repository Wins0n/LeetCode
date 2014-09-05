#include <iostream>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// O(N) ...
class Solution
{
private:
    TreeNode *pre, *p1, *p2;

private:
    void traversal(TreeNode* p)
    {
        if (p)
        {
            traversal(p->left);
            if (pre && pre->val > p->val)
            {
                if (p1 == NULL)
                {
                    p1 = pre;
                    p2 = p;
                }
                else
                {
                    p2 = p;
                }
            }
            pre = p;
            traversal(p->right);
        }
    }

public:
    void recoverTree(TreeNode* root)
    {
        if (root)
        {
            pre = p1 = p2 = NULL;
            traversal(root);
            std::swap(p1->val, p2->val);
        }
    }
};

int main(int argc, char** argv)
{
    Solution sln;

    return 0;
}

