#include <iostream>
#include <algorithm>

/******************************************************************************
// worst case: O(NlgN)
class Solution
{
private:
    bool flag;

private:
    void search(int A[], int l, int r, int target)
    {
        if (l > r)
        {
            return ;
        }
        if (l == r-1)
        {
            if (A[l] == target || A[r] == target)
            {
                flag = true;
            }
            return ;
        }

        if (flag)
        {
            return ;
        }
        
        int m = l + (r-l)/2;
        if (A[m] >= A[l])
        {
            if (std::binary_search(A+l, A+m+1, target))
            {
                flag = true;
            }
            search(A, m+1, r, target);
        }
        if (A[m] <= A[r])
        {
            if (std::binary_search(A+m, A+r+1, target))
            {
                flag = true;
            }
            search(A, l, m-1, target);
        }
    }

public:
    bool search(int A[], int n, int target)
    {
        flag = false;
        search(A, 0, n-1, target);
        return flag;
    }
};
******************************************************************************/

// worst case O(N)
class Solution
{
public:
    bool search(int A[], int n, int target)
    {
        int l = 0;
        int r = n-1;
        
        while (l <= r)
        {
            int m = l + (r-l)/2;
            if (A[l] == target || A[m] == target || A[r] == target)
            {
                return true;
            }
            
            if (A[m] > A[l])
            {
                if (target < A[m] && target > A[l])
                {
                    r = m-1;
                }
                else
                {
                    l = m+1;
                }
            }
            else if (A[m] < A[r])
            {
                if (target < A[r] && target > A[m])
                {
                    l = m+1;
                }
                else
                {
                    r = m-1;
                }
            }
            else
            {
                ++l;
            }
        }
        return false;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    
    return 0;
}

