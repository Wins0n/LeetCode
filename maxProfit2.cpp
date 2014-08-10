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
        for (int i = 1; i < n; ++i)
        {
            if (prices[i] > prices[i-1])
            {
                res += prices[i] - prices[i-1];
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

