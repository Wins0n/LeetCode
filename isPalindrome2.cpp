#include <iostream>

class Solution
{
private:
    int getLength(long long x)
    {
        int res = 0;
        while (x)
        {
            x /= 10;
            ++res;
        }
        return res;
    }

public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        int n = getLength(x);
        int tmp = 1;
        for (int i = 1; i < n; ++i)
        {
            tmp *= 10;
        }
        n /= 2;
        int mod = 10;
        for (int i = 0; i < n; ++i)
        {
            int l = x/tmp%10;
            int r = x%mod/(mod/10);
            if (l != r)
            {
                return false;
            }
            tmp /= 10;
            mod *= 10;
        }
        return true;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    int x;

    while (std::cin >> x)
    {
        std::cout << std::boolalpha << sln.isPalindrome(x) << std::endl;
    }

    return 0;
}

