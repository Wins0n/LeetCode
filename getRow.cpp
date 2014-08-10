#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> getRow(int rowIndex)
    {
        std::vector<int> v(rowIndex+1, 1);
        for (int i = 2; i <= rowIndex; ++i)
        {
            int cur = 1, pre = 1;
            for (int j = 1; j <= (i>>1); ++j)
            {
                cur = v[j];
                v[j] = v[i-j] = v[j] + pre;
                pre = cur;
            }
        }
        return v;
    }
};

int main(int argc, char **argv)
{
    int n;
    Solution sln;
    
    while (std::cin >> n)
    {
        std::vector<int> v = sln.getRow(n);
        for (auto item : v)
        {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}

