#include <iostream>
#include <string>
#include <algorithm>

class Solution
{
public:
    std::string multiply(std::string num1, std::string num2)
    {
        std::string res("0");
        int carry = 0;
        int l = num1.length();
        int r = num2.length();

        int offset = 0;
        for (int i = l-1; i >= 0; --i)
        {
            int k = offset;
            int n = res.length();
            ++offset;
            for (int j = r-1; j >= 0; --j, ++k)
            {
                int tmp = (num2[j]-'0') * (num1[i]-'0') + carry;
                if (k < n)
                {
                    tmp += res[k]-'0';
                }
                if (tmp >= 10)
                {
                    carry = tmp/10;
                    tmp %= 10;
                }
                else
                {
                    carry = 0;
                }
                if (k < n)
                {
                    res[k] = tmp + '0';
                }
                else
                {
                    res.push_back(tmp + '0');
                }
            }
            if (carry)
            {
                res.push_back(carry + '0');
                carry = 0;
            }
        }
        if (carry)
        {
            res.push_back(carry + '0');
        }
        std::reverse(res.begin(), res.end());

        int i = 0;
        int n = res.size();
        while (i < n-1 && res[i] == '0')
        {
            ++i;
        }
        
        return res.substr(i, std::string::npos);
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::string num1, num2;
    
    while (std::cin >> num1 >> num2)
    {
        std::cout << sln.multiply(num1, num2) << std::endl;
    }
    
    return 0;
}

