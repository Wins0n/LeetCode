#include <iostream>

class Solution
{
public:
    int sqrt(int x)
    {
        long long low = 0;
        long long high = x/2 + 1;
        while (low <= high)
        {
            long long mid = low + (high - low)/2;
            long long tmp = mid * mid;
            if (tmp == x)
            {
                return mid;
            }
            if (tmp < x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return high;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    int x;

    while (std::cin >> x)
    {
        std::cout << sln.sqrt(x) << std::endl;
    }

    return 0;
}
