#include <iostream>
#include <vector>

class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        int n = prices.size();
        if (n == 0 || n == 1)
        {
            return 0;
        }
        
        int res = 0;
        int tmp = 0;
        for (int i = 1; i < n; ++i)
        {
            tmp += prices[i] - prices[i-1];
            if (tmp > 0)
            {
                res = std::max(res, tmp);
            }
            else
            {
                tmp = 0;
            }
        }
        return res;
    }
};

int main(int argc, char **argv)
{
    Solution sln;
    
    return 0;
}

