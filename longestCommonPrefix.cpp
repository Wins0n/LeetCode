#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// in C++11 std::string::length() is constant complexity
class StrComp
{
public:
    bool operator()(const std::string& lhs, const std::string& rhs)
    {
        if (lhs.length() == rhs.length())
        {
            return lhs < rhs;
        }
        return lhs.length() < rhs.length();
    }
};

class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs)
    {
        std::sort(strs.begin(), strs.end(), StrComp());
        int n = strs.size();
        std::string res;
        
        if (n == 0)
        {
            return res;
        }

        res = strs[0];
        int len = res.length();
        for (int i = 1; i < n; ++i)
        {
            int tmp = strs[i].length();
            for (int j = 0; j < tmp && j < len; ++j)
            {
                if (strs[i][j] != res[j])
                {
                    len = j;
                    break;
                }
            }
        }
        return res.substr(0, len);
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    
    return 0;
}

