#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution
{
private:
    int fac[10];
    std::vector<char> dict;

private:
    void init()
    {
        fac[0] = 1;
        for (int i = 1; i < 10; ++i)
        {
            fac[i] = fac[i-1] * i;
        }

        dict.clear();
        for (int i = '1'; i <= '9'; ++i)
        {
            dict.push_back(i);
        }
    }

public:
    std::string getPermutation(int n, int k)
    {
        std::string res;
        init();

        while (n > 0)
        {
            int i = (k-1) / fac[n-1];
            res.push_back(dict[i]);
            dict.erase(std::find(dict.begin(), dict.end(), dict[i]));
            k -= i*fac[n-1];
            n -= 1;
        }

        return res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    int n , k;

    while (std::cin >> n >> k)
    {
        std::cout << sln.getPermutation(n, k) << std::endl;
    }

    return 0;
}

