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
    
private:
    void traversal(TreeNode* p, int& val)
    {
        if (p)
        {
            val = val*10 + p->val;
            if (p->left == NULL && p->right == NULL)
            {
                _sum += val;
            }
            else
            {
                traversal(p->left, val);
                traversal(p->right, val);
            }
            val = (val - p->val)/10;
        }
    }
    
public:
    int sumNumbers(TreeNode* root)
    {
        _sum = 0;
        int val = 0;
        traversal(root, val);
        return _sum;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    TreeNode a(4), b(9), c(0), d(1);
    a.left = &b;
    a.right = &c;
    b.right = &d;
    std::cout << sln.sumNumbers(&a) << std::endl;

    return 0;
}

