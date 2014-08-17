#include <iostream>
#include <vector>

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (m == 0 || n == 0)
        {
            return 0;
        }

        std::vector<std::vector<int> > dp(m, std::vector<int>(n, 1));
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    
    return 0;
}

