#include <iostream>

class Solution
{
private:
    double pow(double x, long long n)
    {
        if (n == 0)
        {
            return 1.0;
        }
        if (n < 0)
        {
            return 1.0 / pow(x, -n);
        }
        if (n&1)
        {
            return x * pow(x, n-1);
        }
        
        double tmp = pow(x, n>>1);
        return tmp*tmp;
    }

public:
    double pow(double x, int n)
    {
        return pow(x, static_cast<long long>(n));
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    double x;
    int n;
    
    while (std::cin >> x >> n)
    {
        std::cout << sln.pow(x, n) << std::endl;
    }
    
    return 0;
}

