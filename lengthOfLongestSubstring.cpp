#include <iostream>
#include <string>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int map[256] = {0};
        int n = s.length();
        int res = 0;
        
        for (int i = 0; i < 256; ++i)
        {
            map[i] = -1;
        }
        
        int last = 0;
        int len = 0;
        for (int i = 0; i < n; ++i)
        {
            if (map[s[i]] == -1)
            {
                map[s[i]] = i;
                continue;
            }
            res = std::max(res, i - last);
            while (last <= map[s[i]])
            {
                map[s[last++]] = -1;
            }
            map[s[i]] = i;
        }
        res = std::max(res, n - last);
        
        return res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::string s;

    while (std::cin >> s)
    {
        std::cout << sln.lengthOfLongestSubstring(s) << std::endl;
    }

    return 0;
}

