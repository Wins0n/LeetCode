#include <iostream>
#include <vector>

class Solution
{
public:
    int candy(std::vector<int>& ratings)
    {
        if (ratings.empty())
        {
            return 0;
        }
        int n = ratings.size();
        std::vector<int> count(n, 1);
        for (int i = 1; i < n; ++i)
        {
            if (ratings[i] > ratings[i-1])
            {
                count[i] = count[i-1] + 1;
            }
        }
        int res = count[n-1];
        for (int i = n-2; i >= 0; --i)
        {
            if (ratings[i] > ratings[i+1] && count[i] <= count[i+1])
            {
                count[i] = count[i+1] + 1;
            }
            res += count[i];
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
        std::vector<int> ratings(n, 0);
        for (int i = 0; i < n; ++i)
        {
            std::cin >> ratings[i];
        }
        std::cout << sln.candy(ratings) << std::endl;
    }
    
    return 0;
}

