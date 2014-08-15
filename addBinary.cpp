#include <iostream>
#include <string>
#include <algorithm>

class Solution
{
public:
    std::string addBinary(std::string a, std::string b)
    {
        std::string res;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        
        while (i >= 0 && j >= 0)
        {
            char ch = a[i] + b[j] - '0' + carry;
            if (ch >= '2')
            {
                ch -= 2;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            res.push_back(ch);
            --i;
            --j;
        }
        while (i >= 0)
        {
            char ch = a[i] + carry;
            if (ch >= '2')
            {
                ch -= 2;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            res.push_back(ch);
            --i;
        }
        while (j >= 0)
        {
            char ch = b[j] + carry;
            if (ch >= '2')
            {
                ch -= 2;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            res.push_back(ch);
            --j;
        }
        if (carry)
        {
            res.push_back('1');
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::cout << sln.addBinary("1111", "1111") << std::endl;

    return 0;
}

