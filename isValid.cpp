#include <iostream>
#include <string>
#include <stack>

class Solution
{
public:
    bool isValid(std::string str)
    {
        int n = str.length();
        if (n & 1)
        {
            return false;
        }

        std::stack<char> s;
        for (int i = 0; i < n; ++i)
        {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            {
                s.push(str[i]);
            }
            else if (str[i] == ')')
            {
                if (s.empty() || s.top() != '(')
                {
                    return false;
                }
                s.pop();
            }
            else if (str[i] == ']')
            {
                if (s.empty() || s.top() != '[')
                {
                    return false;
                }
                s.pop();
            }
            else if (str[i] == '}')
            {
                if (s.empty() || s.top() != '{')
                {
                    return false;
                }
                s.pop();
            }
        }
        return s.empty();
    }
};

int main(int argc, char** argv)
{
    Solution sln;

    return 0;
}
