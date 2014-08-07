#include <iostream>
#include <vector>
#include <stack>
#include <iterator>
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
public:
    std::vector<int> postorderTraversal(TreeNode* root)
    {
        std::vector<int> res;
        if (!root)
        {
            return res;
        }
        
        std::stack<TreeNode*> s;
        TreeNode* cur = NULL;
        TreeNode* pre = NULL;
        s.push(root);
        while (!s.empty())
        {
            cur = s.top();
            if ((cur->left == NULL && cur->right == NULL) ||
                (pre != NULL && (pre == cur->left || pre == cur->right)))
            {
                res.push_back(cur->val);
                s.pop();
                pre = cur;
            }
            else
            {
                if (cur->right)
                {
                    s.push(cur->right);
                }
                if (cur->left)
                {
                    s.push(cur->left);
                }
            }
        }
        return res;
    }
};

int main(int argc, char **argv)
{
    TreeNode a(1), b(2), c(3);
    a.right = &b;
    b.left = &c;
    
    Solution sln;
    std::vector<int> res = sln.postorderTraversal(&a);
    std::copy(res.begin(), res.end(),
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}

