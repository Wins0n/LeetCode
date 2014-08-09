#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

class Solution
{
public:
    bool isPalindrome(std::string s)
    {
        if (s.empty())
        {
            return true;
        }
        
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        int r = s.length() - 1;
        int l = 0;
        do
        {
            while (l < r && !isalnum(s[l])) ++l;
            while (l < r && !isalnum(s[r])) --r;
            if (l >= r) break;
            if (s[l] != s[r]) return false;
            ++l;
            --r;
        } while (true);
        return true;
    }
};

int main(int argc, char **argv)
{
    Solution sln;
    std::string s[] = {
        "A man, a plan, a canal: Panama",
        "race a car"
    };
    std::cout << std::boolalpha << sln.isPalindrome(s[0]) << std::endl;
    std::cout << std::boolalpha << sln.isPalindrome(s[1]) << std::endl;
    
    return 0;
}

