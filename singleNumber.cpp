#include <iostream>
#include <vector>

class Solution
{
public:
    int singleNumber(int A[], int n)
    {
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            res ^= A[i];
        }
        return res;
    }
};

int main(int argc, char **argv)
{
    Solution sln;
    int n;
    while (std::cin >> n)
    {
        std::vector<int> v(n, 0);
        for (int i = 0; i < n; ++i)
        {
            std::cin >> v[i];
        }
        std::cout << sln.singleNumber(&v[0], n) << std::endl;
    }
    
    return 0;
}
