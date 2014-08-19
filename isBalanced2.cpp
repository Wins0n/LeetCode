#include <iostream>
#include <cstdlib>

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
    bool isBalanced(TreeNode* p, int& depth)
    {
        if (p == NULL)
        {
            depth = 0;
            return true;
        }

        int left = 0;
        int right = 0;
        if (isBalanced(p->left, left) && isBalanced(p->right, right))
        {
            if (abs(left - right) > 1)
            {
                return false;
            }
            depth = std::max(left, right) + 1;
            return true;
        }
        return false;
    }

public:
    bool isBalanced(TreeNode* root)
    {
        int depth = 0;
        return isBalanced(root, depth);
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    
    return 0;
}

