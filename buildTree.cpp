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
    TreeNode* buildTree(int* in, int* post, int n)
    {
        if (n <= 0)
        {
            return NULL;
        }
        TreeNode* p = new TreeNode(post[n-1]);
        int* pos = std::find(in, in+n, post[n-1]);
        int m = pos - in;
        p->left = buildTree(in, post, m);
        p->right = buildTree(in+m+1, post+m, n-m-1);
        return p;
    }
    
public:
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder)
    {
        if (inorder.empty())
        {
            return NULL;
        }
        return buildTree(&inorder[0], &postorder[0], postorder.size());
    }
};

int main(int argc, char **argv)
{
    Solution sln;
    
    return 0;
}

