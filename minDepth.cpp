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
    void Traversal(TreeNode* p, int cur_depth)
    {
        if (p->left == NULL && p->right == NULL)
        {
            if (cur_depth < _depth)
            {
                _depth = cur_depth;
            }
            return ;
        }
        if (p->left)
        {
            Traversal(p->left, cur_depth+1);
        }
        if (p->right)
        {
            Traversal(p->right, cur_depth+1);
        }
    }
    
public:
    int minDepth(TreeNode* root)
    {
        if (root)
        {
            _depth = 0x7FFFFFFF;
            Traversal(root, 1);
        }
        else
        {
            _depth = 0;
        }
        return _depth;
    }
};

int main(int argc, char **argv)
{
    Solution sln;
    
    return 0;
}

