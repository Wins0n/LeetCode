#include <iostream>
#include <limits>
#include <string>

class Solution
{
public:
    int atoi(const char* str)
    {
        long long res = 0;
        while (*str && *str == ' ')
        {
            ++str;
        }

        bool negative = false;
        if (*str == '-')
        {
            negative = true;
            ++str;
        }
        else if (*str == '+')
        {
            ++str;
        }

        while (*str && *str >= '0' && *str <= '9')
        {
            res = res*10 + *str-'0';
            ++str;
        }

        if (negative)
        {
            res = -res;
        }
        
        if (res >= std::numeric_limits<int>::max())
        {
            res = std::numeric_limits<int>::max();
        }
        else if (res <= std::numeric_limits<int>::min())
        {
            res = std::numeric_limits<int>::min();
        }
        return static_cast<int>(res);
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::string s;
    while (std::cin >> s)
    {
        std::cout << sln.atoi(s.c_str()) << std::endl;
    }

    return 0;
}

