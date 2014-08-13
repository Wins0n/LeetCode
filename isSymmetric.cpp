#include <iostream>
#include <vector>
#include <queue>

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
    bool isSymmetric(TreeNode* l, TreeNode* r)
    {
        if (!l && !r)
        {
            return true;
        }
        if (!l || !r)
        {
            return false;
        }
        if (l->val == r->val && isSymmetric(l->left, r->right) && 
            isSymmetric(l->right, r->left))
        {
            return true;
        }
        return false;
    }
    
public:
    bool isSymmetric(TreeNode* root)
    {
        return isSymmetric(root, root);
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    TreeNode a(1), b(2);
    a.left = &b;

    std::cout << std::boolalpha << sln.isSymmetric(&a) << std::endl;

    return 0;
}

