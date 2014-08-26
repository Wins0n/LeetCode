#include <iostream>
#include <string>
#include <vector>

int inline min(int x, int y, int z)
{
    return std::min(std::min(x, z), std::min(y, z));
}

class Solution
{
public:
    int minDistance(std::string word1, std::string word2)
    {
        int l = word1.length() + 1;
        int r = word2.length() + 1;
        
        std::vector<std::vector<int> > dp(l, std::vector<int>(r, 0));
        for (int i = 0; i < l; ++i)
        {
            dp[i][0] = i;
        }
        for (int i = 0; i < r; ++i)
        {
            dp[0][i] = i;
        }
        
        for (int i = 1; i < l; ++i)
        {
            for (int j = 1; j < r; ++j)
            {
                dp[i][j] = dp[i-1][j-1];
                if (word1[i-1] != word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i][j]);
            }
        }
        return dp[l-1][r-1];
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::string l, r;

    while (std::cin >> l >> r)
    {
        std::cout << sln.minDistance(l, r) << std::endl;
    }
    
    return 0;
}

