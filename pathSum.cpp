#include <iostream>
#include <vector>

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
    std::vector<std::vector<int> > _v;
    std::vector<int> _vPath;
private:
    void Traversal(TreeNode* p, int sum)
    {
        _vPath.push_back(p->val);
        sum += p->val;
        if (p->left == NULL && p->right == NULL)
        {
            if (sum == _sum)
            {
                _v.push_back(_vPath);
            }
            _vPath.pop_back();
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
        _vPath.pop_back();
    }
    
public:
    std::vector<std::vector<int> > pathSum(TreeNode* root, int sum)
    {
        _sum = sum;
        _v.clear();
        if (root)
        {
            Traversal(root, 0);
        }
        return _v;
    }
};

int main(int argc, char **argv)
{
    Solution sln;
    
    return 0;
}

