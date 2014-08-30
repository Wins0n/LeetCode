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
    int res;

private:
    int traversal(TreeNode* p)
    {
        if (p == NULL)
        {
            return 0;
        }
        int left = traversal(p->left);
        int right = traversal(p->right);
        int tmp = p->val;
        if (left > 0)
        {
            tmp += left;
        }
        if (right > 0)
        {
            tmp += right;
        }
        res = std::max(res, tmp);
        
        if (left < 0 && right < 0)
        {
            return p->val;
        }
        return p->val + std::max(left, right);
    }

public:
    int maxPathSum(TreeNode* root)
    {
        res = std::numeric_limits<int>::min();
        if (root)
        {
            traversal(root);
        }
        return res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;

    return 0;
}
