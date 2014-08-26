#include <iostream>

class Solution
{
private:
    int numTrees(int beg, int end)
    {
        if (beg >= end)
        {
            return 1;
        }
        
        int res = 0;
        for (int i = beg; i <= end; ++i)
        {
            res += numTrees(beg, i-1) * numTrees(i+1, end);
        }
        return res;
    }

public:
    int numTrees(int n)
    {
        return numTrees(1, n);
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    int n;
    
    while (std::cin >> n)
    {
        std::cout << sln.numTrees(n) << std::endl;
    }
    
    return 0;
}

