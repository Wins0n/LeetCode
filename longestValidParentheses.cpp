#include <iostream>
#include <string>
#include <stack>

class Solution
{
private:
    enum
    {
        L = -1,
        R = -2
    };
    
public:
    int longestValidParentheses(std::string s)
    {
        std::stack<int> _stack;
        int n = s.length();
        int res = 0;

        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '(')
            {
                _stack.push(L);
            }
            else
            {
                int sum = 0;
                while (!_stack.empty())
                {
                    int tmp = _stack.top();
                    if (tmp > 0)
                    {
                        sum += tmp;
                        _stack.pop();
                    }
                    else
                    {
                        if (tmp == L)
                        {
                            _stack.pop();
                            _stack.push(sum + 2);
                        }
                        else
                        {
                            _stack.push(sum);
                            _stack.push(R);
                        }
                        break;
                    }
                }
                if (sum > res)
                {
                    res = sum;
                }
            }
        }
        
        int sum = 0;
        while (!_stack.empty())
        {
            int tmp = _stack.top();
            if (tmp > 0)
            {
                sum += tmp;
            }
            else
            {
                if (sum > res)
                {
                    res = sum;
                }
                sum = 0;
            }
            _stack.pop();
        }
        if (sum > res)
        {
            res = sum;
        }
        
        return res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::string s;
    while (std::cin >> s)
    {
        std::cout << sln.longestValidParentheses(s) << std::endl;
    }

    return 0;
}

