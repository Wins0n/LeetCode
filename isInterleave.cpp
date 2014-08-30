#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    bool isInterleave(std::string& s1, std::string& s2, std::string& s3)
    {
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();
        if (l3 != l1 + l2)
        {
            return false;
        }
        
        std::vector<std::vector<bool> > dp(l1+1, std::vector<bool>(l2+1, false));
        dp[0][0] = true;
        for (int i = 1; i <= l1; ++i)
        {
            if (s1[i-1] == s3[i-1])
            {
                dp[i][0] = true;
            }
            else
            {
                break;
            }
        }
        for (int j = 1; j <= l2; ++j)
        {
            if (s2[j-1] == s3[j-1])
            {
                dp[0][j] = true;
            }
            else
            {
                break;
            }
        }
        
        for (int i = 1; i <= l1; ++i)
        {
            for (int j = 1; j <= l2; ++j)
            {
                if (s1[i-1] == s3[i+j-1])
                {
                    dp[i][j] = dp[i][j] || dp[i-1][j];
                }
                if (s2[j-1] == s3[i+j-1])
                {
                    dp[i][j] = dp[i][j] || dp[i][j-1];
                }
            }
        }
        
        return dp[l1][l2];
    }
};

int main(int argc, char** argv)
{
    std::string s1, s2, s3;
    Solution sln;

    while (std::cin >> s1 >> s2 >> s3)
    {
        std::cout << std::boolalpha << sln.isInterleave(s1, s2, s3) << std::endl;
    }

    return 0;
}

