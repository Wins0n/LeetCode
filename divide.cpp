#include <iostream>

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        unsigned int a = dividend < 0 ? -dividend : dividend;
        unsigned int b = divisor < 0 ? -divisor : divisor;
        bool neg = false;
        if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0)
        {
            neg = true;
        }
        
        int res = 0;
        while (a >= b)
        {
            long long tmp = b;
            int i = 0;
            while (tmp <= a)
            {
                tmp = (tmp << 1);
                ++i;
            }
            res += (1<<(i-1));
            a -= (b<<(i-1));
        }
        return neg ? -res : res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    int dividend, divisor;

    while (std::cin >> dividend >> divisor)
    {
        std::cout << sln.divide(dividend, divisor) << std::endl;
    }

    return 0;
}
