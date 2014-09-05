#include <iostream>
#include <algorithm>
#include <vector>

class Solution
{
public:
    std::vector<int> searchRange(int A[], int n, int target)
    {
        std::vector<int> res(2, -1);
        int l = std::lower_bound(A, A+n, target) - A;
        int r = std::upper_bound(A, A+n, target) - A;
        if (l != n && A[l] == target)
        {
            res[0] = l;
            res[1] = r-1;
        }
        return res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::vector<int> A = {5, 7, 7, 8, 8, 10};
    std::vector<int> res = sln.searchRange(&A[0], A.size(), 8);

    std::cout << res[0] << ", " << res[1] << std::endl;

    return 0;
}

