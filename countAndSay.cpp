#include <iostream>
#include <string>
#include <cstdio>

class Solution
{
public:
    std::string countAndSay(int n)
    {
        std::string res("1");
        for (int i = 1; i < n; ++i)
        {
            int val = res[0] - '0';
            int count = 1;
            int len = res.length();
            int index = 1;
            std::string tmp;
            while (index <= len)
            {
                if (index < len && res[index] == res[index-1])
                {
                    ++count;
                }
                else
                {
                    char buff[256] = {0};
                    sprintf(buff, "%d%d", count, val);
                    tmp.append(buff);
                    val = res[index] - '0';
                    count = 1;
                }
                ++index;
            }
            res = tmp;
        }

        return res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    int n;
    
    while (std::cin >> n)
    {
        std::cout << sln.countAndSay(n) << std::endl;
    }
    
    return 0;
}

