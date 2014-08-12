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
    int _sum;
    bool _find;

private:
    void Traversal(TreeNode* p, int sum)
    {
        if (_find)
        {
            return ;
        }
        sum += p->val;
        if (p->left == NULL && p->right == NULL)
        {
            _find = (sum == _sum);
            return ;
        }
        if (p->left)
        {
            Traversal(p->left, sum);
        }
        if (p->right)
        {
            Traversal(p->right, sum);
        }
    }
    
public:
    bool hasPathSum(TreeNode* root, int sum)
    {
        _sum = sum;
        _find = false;
        if (root)
        {
            Traversal(root, 0);
        }
        return _find;
    }
};

int main(int argc, char **argv)
{
    Solution sln;
    
    return 0;
}

