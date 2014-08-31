#include <iostream>
#include <vector>
#include <string>
#include <cstring>

class Solution
{
public:
    bool isMatch(const char* s, const char* p)
    {
        int n = strlen(s);
        int m = strlen(p);
        
        // optimization
        int tmp = 0;
        const char* pp = p;
        while (*pp)
        {
            if (*pp != '*')
            {
                ++tmp;
            }
            ++pp;
        }
        if (tmp > n)
        {
            return false;
        }
        
        // optimization
        if (*p != '?' && *p != '*' && *p != *s)
        {
            return false;
        }
        
        // vector will cause MLE
        bool** dp = new bool*[n+1];
        for (int i = 0; i <= n; ++i)
        {
            dp[i] = new bool[m+1];
            memset(dp[i], 0, sizeof(bool)*(m+1));
        }
        
        dp[0][0] = true;
        for (int j = 1; j <= m; ++j)
        {
            if (p[j-1] == '*')
            {
                dp[0][j] = true;
            }
            else
            {
                break;
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (p[j-1] == '?' || s[i-1] == p[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j-1] == '*')
                {
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }

        bool res = dp[n][m];
        for (int i = 0; i <= n; ++i)
        {
            delete [](dp[i]);
        }
        return res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::string s, p;
    while (std::cin >> s >> p)
    {
        std::cout << std::boolalpha << sln.isMatch(s.c_str(), p.c_str()) << std::endl;
    }
    
    return 0;
}

