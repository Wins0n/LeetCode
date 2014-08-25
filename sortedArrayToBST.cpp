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
    TreeNode* imp(const int* arr, int n)
    {
        if (n == 0)
        {
            return NULL;
        }
        if (n == 1)
        {
            return new TreeNode(arr[0]);
        }
        TreeNode* p = new TreeNode(arr[n/2]);
        p->left = imp(arr, n/2);
        p->right = imp(arr+n/2+1, n-n/2-1);
        return p;
    }

public:
    TreeNode* sortedArrayToBST(std::vector<int>& num)
    {
        int n = num.size();
        if (n)
        {
            return imp(&num[0], n);
        }
        return NULL;
    }
};

int main(int argc, char** argv)
{
    Solution sln;

    return 0;
}

