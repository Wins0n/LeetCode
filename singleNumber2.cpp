#include <iostream>

class Solution
{
public:
    int singleNumber(int A[], int n)
    {
        int ones = 0;
        int twos = 0;
        int threes = 0;
        for (int i = 0; i < n; ++i)
        {
            twos = twos | (ones & A[i]);
            ones = ones ^ A[i];
            threes = ones & twos;
            ones = ones & (~threes);
            twos = twos & (~threes);
        }
        return ones;
    }
};

int main(int argc, char **argv)
{
    Solution sln;
    
    return 0;
}

