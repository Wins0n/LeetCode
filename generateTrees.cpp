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
    std::vector<TreeNode*> generateTrees(int beg, int end)
    {
        std::vector<TreeNode*> res;
        if (beg > end)
        {
            res.push_back(NULL);
        }
        
        for (int i = beg; i <= end; ++i)
        {
            std::vector<TreeNode*> left = generateTrees(beg, i-1);
            std::vector<TreeNode*> right = generateTrees(i+1, end);
            for (int l = 0; l < left.size(); ++l)
            {
                for (int r = 0; r < right.size(); ++r)
                {
                    TreeNode* p = new TreeNode(i);
                    p->left = left[l];
                    p->right = right[r];
                    res.push_back(p);
                }
            }
        }
        return res;
    }

public:
    std::vector<TreeNode*> generateTrees(int n)
    {
        return generateTrees(1, n);
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    
    return 0;
}

