#include <iostream>

class Solution
{
public:
    int searchInsert(int A[], int n, int target)
    {
        int l = 0;
        int r = n-1;
        int m = 0;
        
        if (n == 0 || A[0] > target)
        {
            return 0;
        }
        if (A[n-1] < target)
        {
            return n;
        }
        
        while (l < r)
        {
            m = l + (r-l)/2;
            if (A[m] == target)
            {
                return m;
            }
            else if (A[m] > target)
            {
                r = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        if (target < A[l])
        {
            return l;
        }
        if (target > A[r])
        {
            return r+1;
        }
        return r;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    const int n = 3;
    int A[n] = {1, 3, 5};
    
    std::cout << sln.searchInsert(A, n, 2) << std::endl;
    
    return 0;
}

