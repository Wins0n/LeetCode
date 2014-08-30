#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    void nextPermutation(std::vector<int>& num)
    {
        int n = num.size();
        for (int i = n-1; i >= 1; --i)
        {
            if (num[i-1] < num[i])
            {
                for (int j = n-1; j >= i; --j)
                {
                    if (num[j] > num[i-1])
                    {
                        std::swap(num[i-1], num[j]);
                        std::reverse(num.begin()+i, num.end());
                        return ;
                    }
                }
            }
        }
        std::reverse(num.begin(), num.end());
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    
    return 0;
}

