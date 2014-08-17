#include <iostream>

class Solution
{
public:
    int removeDuplicates(int A[], int n)
    {
        if (n == 0)
        {
            return 0;
        }
        int l = 0;
        int i = 1;
        while (i < n)
        {
            while (i < n && A[i] == A[l])
            {
                ++i;
            }
            if (i >= n)
            {
                break;
            }
            A[++l] = A[i];
            ++i;
        }
        n = ++l;
        
        return n;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    const int n = 3;
    int A[n] = {1, 1, 2};
    
    int m = sln.removeDuplicates(A, n);
    for (int i = 0; i < m; ++i)
    {
        std::cout << A[i] <<  " ";
    }
    std::cout << std::endl;
    
    return 0;
}

