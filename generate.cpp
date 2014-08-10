#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int> > generate(int numRows)
    {
        std::vector<std::vector<int> > res;
        if (numRows == 0)
        {
            return res;
        }
        res.push_back(std::vector<int>(1, 1));
        if (numRows == 1)
        {
            return res;
        }
        res.push_back(std::vector<int>(2, 1));
        for (int i = 2; i < numRows; ++i)
        {
            std::vector<int> v(i+1, 1);
            for (int j = 1; j < i; ++j)
            {
                v[j] = res[i-1][j-1] + res[i-1][j];
            }
            res.push_back(v);
        }
        return res;
    }
};

int main(int argc, char **argv)
{
    int n;
    Solution sln;

    while (std::cin >> n)
    {
        std::vector<std::vector<int> > v = sln.generate(n);
        for (auto outer : v)
        {
            for (auto inner : outer)
            {
                std::cout << inner << " ";
            }
            std::cout << std::endl;
        }
    }
    
    return 0;
}

