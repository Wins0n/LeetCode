#include <iostream>

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
    int _depth;

private:
    void Traversal(TreeNode* p, int depth)
    {
        if (p->left == NULL && p->right == NULL)
        {
            if (depth > _depth)
            {
                _depth = depth;
            }
            return ;
        }
        if (p->left)
        {
            Traversal(p->left, depth+1);
        }
        if (p->right)
        {
            Traversal(p->right, depth+1);
        }
    }
    
public:
    int maxDepth(TreeNode* root)
    {
        _depth = 0;
        if (root)
        {
            Traversal(root, 1);
        }
        return _depth;
    }
};

int main(int argc, char **argv)
{
    Solution sln;
    
    return 0;
}

