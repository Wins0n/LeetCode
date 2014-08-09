#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <iterator>

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
    std::vector<int> preorderTraversal(TreeNode* root)
    {
        std::vector<int> res;
        std::stack<TreeNode*> s;
        while (root || !s.empty())
        {
            while (root)
            {
                res.push_back(root->val);
                s.push(root);
                root = root->left;
            }
            if (!s.empty())
            {
                root = s.top();
                s.pop();
                root = root->right;
            }
        }
        return res;
    }
};

int main(int argc, char **argv)
{
    Solution sln;
    TreeNode a(1), b(2), c(3);
    a.right = &b;
    b.left = &c;

    std::vector<int> v = sln.preorderTraversal(&a);
    std::copy(v.begin(), v.end(), 
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    
    return 0;
}
