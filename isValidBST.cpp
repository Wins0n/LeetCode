#include <iostream>
#include <limits>

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
    bool isValidBST(TreeNode* p, long long left, long long right)
    {
        if (p == NULL)
        {
            return true;
        }
        if (p->val <= left || p->val >= right)
        {
            return false;
        }
        return isValidBST(p->left, left, p->val) &&
               isValidBST(p->right, p->val, right);
    }

public:
    bool isValidBST(TreeNode* root)
    {
        long long left = std::numeric_limits<int>::min();
        long long right = std::numeric_limits<int>::max();
        return isValidBST(root, left-1, right+1);
    }
};

int main(int argc, char** argv)
{
    Solution sln;

    return 0;
}

