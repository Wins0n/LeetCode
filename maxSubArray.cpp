#include <iostream>

class Solution
{
public:
    int maxSubArray(int A[], int n)
    {
        if (n == 0)
        {
            return 0;
        }
        
        int res = A[0];
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += A[i];
            if (sum > res)
            {
                res = sum;
            }
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    const int n = 9;
    int A[n] = {-2,1,-3,4,-1,2,1,-5,4};
    
    std::cout << sln.maxSubArray(A, n) << std::endl;
    
    return 0;
}

