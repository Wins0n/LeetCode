#include <iostream>
#include <vector>
#include <string>
#include <stack>

class Solution
{
private:
    int str2int(const std::string& s)
    {
        int res = 0;
        int n = s.length();
        int i = 0;
        bool negative = s[0] == '-';
        if (negative)
        {
            i = 1;
        }
        for (; i < n; ++i)
        {
            res = res*10 + s[i]-'0';
        }
        return negative ? -res : res;
    }

public:
    int evalRPN(std::vector<std::string>& tokens)
    {
        std::stack<int> rpn;
        std::vector<std::string>::iterator iter = tokens.begin();
        while (iter != tokens.end())
        {
            char op = (*iter)[0];
            if (iter->length() == 1 && 
                (op == '+' || op == '-' || op == '*' || op == '/'))
            {
                int rhs = rpn.top();
                rpn.pop();
                int lhs = rpn.top();
                rpn.pop();
                if (op == '+')
                {
                    rpn.push(lhs + rhs);
                }
                else if (op == '-')
                {
                    rpn.push(lhs - rhs);
                }
                else if (op == '*')
                {
                    rpn.push(lhs * rhs);
                }
                else
                {
                    rpn.push(lhs / rhs);
                }
            }
            else
            {
                rpn.push(str2int(*iter));
            }
            ++iter;
        }
        
        if (!rpn.empty())
        {
            return rpn.top();
        }
        return 0;
    }
};

int main(int argc, char **argv)
{
    std::string s;
    std::vector<std::string> tokens;
    Solution sln;

    while (std::cin >> s)
    {
        if (s == "END")
        {
            std::cout << sln.evalRPN(tokens) << std::endl;
            tokens.clear();
        }
        tokens.push_back(s);
    }

    return 0;
}
