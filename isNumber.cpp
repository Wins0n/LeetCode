#include <iostream>
#include <string>
#include <cstring>

class Solution
{
private:
    bool isnum(const char* s, int beg, int end)
    {
        if (beg > end)
        {
            return false;
        }
        
        while (beg <= end && s[beg] >= '0' && s[beg] <= '9')
        {
            ++beg;
        }
        return beg > end;
    }
    
public:
    bool isNumber(const char* s)
    {
        int l = 0;
        int r = strlen(s) - 1;
        
        // spaces
        while(l <= r && s[l] == ' ')
        {
            ++l;
        }
        while (l <= r && s[r] == ' ')
        {
            --r;
        }
        if (l > r)
        {
            return false;
        }
        
        // first character
        if ((s[l] < '0' || s[l] > '9') &&
            (s[l] != '+' && s[l] != '-' && s[l] != '.'))
        {
            return false;
        }
        
        bool dot = false;
        if (s[l] == '+' || s[l] == '-')
        {
            ++l;
        }
        if (s[l] == '.')
        {
            ++l;
            dot = true;
        }
        if (l > r)
        {
            return false;
        }
        if (s[l] < '0' || s[l] > '9')
        {
            return false;
        }
        
        while (l <= r)
        {
            if (s[l] == '.')
            {
                if (dot)
                {
                    return false;
                }
                dot = true;
            }
            else if (s[l] == 'e' || s[l] == 'E')
            {
                ++l;
                if (l <= r && (s[l] == '+' || s[l] == '-'))
                {
                    ++l;
                }
                return isnum(s, l, r);
            }
            else if(s[l] < '0' || s[l] > '9')
            {
                return false;
            }
            ++l;
        }
        return true;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::string s;
    
    while (std::getline(std::cin, s))
    {
        std::cout << std::boolalpha << sln.isNumber(s.c_str()) << std::endl;
    }
    
    return 0;
}

