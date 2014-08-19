#include <iostream>
#include <vector>

class Solution
{
public:
    bool canJump(int A[], int n)
    {
        int maxIndex = 0;
        for (int i = 0; i < n && maxIndex < n-1; ++i)
        {
            if (i <= maxIndex && i + A[i] > maxIndex)
            {
                maxIndex = i + A[i];
            }
        }
        return maxIndex >= n-1;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    int A[] = {2,3,1,1,4};
    int B[] = {3,2,1,0,4};
    
    std::cout << std::boolalpha << sln.canJump(A, 5) << std::endl;
    std::cout << std::boolalpha << sln.canJump(B, 5) << std::endl;
    
    return 0;
}

