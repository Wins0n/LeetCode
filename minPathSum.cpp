#include <iostream>
#include <vector>

class Solution
{
public:
    int minPathSum(std::vector<std::vector<int> > &grid) 
    {
        int n = grid.size();
        int m = 0;
        if (n > 0)
        {
            m = grid[0].size();
        }
        if (n == 0 || m == 0)
        {
            return 0;
        }
        
        std::vector<std::vector<int> > dp(n, std::vector<int>(m, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < n; ++i)
        {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for (int i = 1; i < m; ++i)
        {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        
        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < m; ++j)
            {
                dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[n-1][m-1];
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::vector<std::vector<int> > v = {{1,2}, {1,1}};
    std::cout << sln.minPathSum(v) << std::endl;
    
    return 0;
}

