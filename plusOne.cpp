#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int> &digits) 
    {
        std::vector<int> v;
        int n = digits.size();
        v.reserve(n+1);
        
        int carry = 1;
        int tmp = 0;
        for (int i = n-1; i >= 0; --i)
        {
            tmp = digits[i] + carry;
            if (tmp >= 10)
            {
                tmp -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            v.push_back(tmp);
        }
        if (carry)
        {
            v.push_back(carry);
        }
        std::reverse(v.begin(), v.end());
        return v;
    }
};

int main(int argc, char** argv)
{
    Solution sln;

    return 0;
}

