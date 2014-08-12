#include <iostream>
#include <vector>
#include <algorithm>

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
    TreeNode* buildTree(int* pre, int* in, int n)
    {
        if (n <= 0)
        {
            return NULL;
        }
        TreeNode* p = new TreeNode(pre[0]);
        int* pos = std::find(in, in+n, pre[0]);
        int m = pos - in;
        p->left = buildTree(pre+1, in, m);
        p->right = buildTree(pre+m+1, in+m+1, n-m-1);
        return p;
    }
    
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
    {
        if (preorder.empty())
        {
            return NULL;
        }
        return buildTree(&preorder[0], &inorder[0], preorder.size());
    }
};

int main(int argc, char **argv)
{
    Solution sln;
    
    return 0;
}

