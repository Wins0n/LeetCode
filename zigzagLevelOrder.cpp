#include <iostream>
#include <vector>
#include <queue>
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
    std::vector<std::vector<int> > zigzagLevelOrder(TreeNode* root)
    {
        std::vector<std::vector<int> > res;
        if (root)
        {
            bool flip = false;
            std::vector<int> v;
            std::queue<TreeNode*> q;
            q.push(root);
            q.push(NULL);
            while (!q.empty())
            {
                TreeNode* p = q.front();
                q.pop();
                if (NULL == p)
                {
                    if (flip)
                    {
                        std::reverse(v.begin(), v.end());
                    }
                    res.push_back(v);
                    v.clear();
                    if (q.empty())
                    {
                        break;
                    }
                    q.push(NULL);
                    flip = !flip;
                }
                else
                {
                    v.push_back(p->val);
                    if (p->left)
                    {
                        q.push(p->left);
                    }
                    if (p->right)
                    {
                        q.push(p->right);
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    TreeNode a(3), b(9), c(20), d(15), e(7);
    a.left = &b;
    a.right = &c;
    c.left = &d;
    c.right = &e;
    
    std::vector<std::vector<int> > v = sln.zigzagLevelOrder(&a);
    for (auto vec : v)
    {
        for (auto item : vec)
        {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}

