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
    int getDepth(TreeNode* p)
    {
        if (p == NULL)
        {
            return 0;
        }
        return std::max(getDepth(p->left), getDepth(p->right)) + 1;
    }

public:
    bool isBalanced(TreeNode* root)
    {
        if (root == NULL)
        {
            return true;
        }
        if (abs(getDepth(root->left) - getDepth(root->right)) > 1)
        {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    
    return 0;
}

