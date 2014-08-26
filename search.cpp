#include <iostream>

class Solution
{
private:
    int binary_search(int A[], int l, int r, int val)
    {
        while (l <= r)
        {
            int m = l + (r-l)/2;
            if (A[m] < val)
            {
                l = m+1;
            }
            else if (A[m] > val)
            {
                r = m-1;
            }
            else
            {
                return m;
            }
        }
        return -1;
    }

    int search(int A[], int l, int r, int target)
    {
        if (l > r)
        {
            return -1;
        }
        if (l == r-1)
        {
            if (A[l] == target)
            {
                return l;
            }
            else if (A[r] == target)
            {
                return r;
            }
            return -1;
        }
        
        int m = l + (r-l)/2;
        if (A[m] > A[l])
        {
            int res = binary_search(A, l, m, target);
            if (res != -1)
            {
                return res;
            }
            return search(A, m+1, r, target);
        }
        if (A[m] < A[r])
        {
            int res = binary_search(A, m, r, target);
            if (res != -1)
            {
                return res;
            }
            return search(A, l, m-1, target);
        }
        if (A[m] == target)
        {
            return m;
        }
        return -1;
    }

public:
    int search(int A[], int n, int target)
    {
        return search(A, 0, n-1, target);
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    int A[] = {3, 1};
    
    std::cout << sln.search(A, 2, 1) << std::endl;

    return 0;
}

