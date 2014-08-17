#include <iostream>
#include <cstring>

class Solution
{
public:
    int lengthOfLastWord(const char* s)
    {
        int r = strlen(s) - 1;
        while (r >= 0 && s[r] == ' ')
        {
            --r;
        }
        int l = r;
        while (l >= 0 && s[l] != ' ')
        {
            --l;
        }
        return r - l;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::cout << sln.lengthOfLastWord("Hello World") << std::endl;

    return 0;
}

