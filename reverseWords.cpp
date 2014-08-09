#include <iostream>
#include <string>

class Solution
{
public:
    void reverseWords(std::string& s)
    {
        if (s.empty()) return ;
        
        std::string res;
        int right = s.length() - 1;
        int left = 0;
        while (left <= right && s[left] == ' ') ++left;
        while (left <= right && s[right] == ' ') --right;
        
        while (true)
        {
            int l = right;
            int r = right;
            while (r >= left && s[r] == ' ') --r;
            l = r;
            while (l >= left && s[l] != ' ') --l;
            res.append(s.substr(l+1, r-l));
            if (l == left - 1)
            {
                break;
            }
            res.append(" ");
            right = l - 1;
        }
        
        s = res;
    }
};

int main(int argc, char **argv)
{
    std::string s;
    Solution sln;
    
    while (getline(std::cin, s))
    {
        sln.reverseWords(s);
        std::cout << s << std::endl;
    }
    
    return 0;
}

