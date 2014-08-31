#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int minCut(std::string s)
    {
        int n = s.length();
        std::vector<std::vector<bool> > pal(n, std::vector<bool>(n, false));
        std::vector<int> dp(n, 0);
        
        for (int i = 0; i < n; ++i)
        {
            dp[i] = n - 1 - i;
        }
        for (int i = n-1; i >= 0; --i)
        {
            for (int j = i; j < n; ++j)
            {
                if (s[i] == s[j])
                {
                    if (j - i <= 1 || (i+1 < n && j-1 >= 0 && pal[i+1][j-1]))
                    {
                        pal[i][j] = true;
                        if (j+1 < n)
                        {
                            dp[i] = std::min(dp[i], dp[j+1]+1);
                        }
                        else
                        {
                            dp[i] = 0;
                        }
                    }
                }
            }
        }
        return dp[0];
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::string s;
    
    while (std::cin >> s)
    {
        std::cout << sln.minCut(s) << std::endl;
    }
    
    return 0;
}

