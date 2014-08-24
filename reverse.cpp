#include <iostream>
#include <limits>
#include <stdexcept>

class Solution
{
public:
    int reverse(int x)
    {
        long long res = 0;
        bool negative = false;
        
        if (x < 0)
        {
            x = -x;
            negative = true;
        }
        while (x > 0)
        {
            res = res*10 + x%10;
            x /= 10;
        }
        if (res > std::numeric_limits<int>::max())
        {
            throw std::overflow_error("reverse failed.");
        }
        if (negative)
        {
            res = -res;
        }
        
        return static_cast<int>(res);
    }
};

int main(int argc, char** argv)
{
    int val;
    Solution sln;

    while (std::cin >> val)
    {
        std::cout << sln.reverse(val) << std::endl;
    }
    return 0;
}
