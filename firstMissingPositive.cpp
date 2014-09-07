#include <iostream>

class Solution
{
public:
    int firstMissingPositive(int A[], int n)
    {
        int i;
        for (i = 0; i < n; ++i)
        {
            while (A[i] > 0 && A[i] < n && A[i] != i+1 && A[i] != A[A[i]-1])
            {
                std::swap(A[i], A[A[i]-1]);
            }
        }
        for (i = 0; i < n; ++i)
        {
            if (A[i] != i+1)
            {
                break;
            }
        }
        return i+1;
    }
};

int main(int argc, char** argv)
{
    int a[] = {1, 1};
    Solution sln;
    std::cout << sln.firstMissingPositive(a, 2) << std::endl;

    return 0;
}
