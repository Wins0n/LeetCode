#include <iostream>
#include <vector>
#include <string>

class Solution
{
private:
    std::vector<std::string> _res;
    std::string _s;

private:
    void generate(int l, int r)
    {
        if (l == 0)
        {
            for (int i = 0; i < r; ++i)
            {
                _s.push_back(')');
            }
            _res.push_back(_s);
            for (int i = 0; i < r; ++i)
            {
                _s.pop_back();
            }
            return ;
        }

        _s.push_back('(');
        generate(l-1, r);
        _s.pop_back();
        
        if (!_s.empty() && l < r)
        {
            _s.push_back(')');
            generate(l, r-1);
            _s.pop_back();
        }
    }

public:
    std::vector<std::string> generateParenthesis(int n)
    {
        _res.clear();
        _s.clear();
        generate(n, n);
        
        return _res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::vector<std::string> vec = sln.generateParenthesis(3);
    for (auto item : vec)
    {
        std::cout << item << std::endl;
    }
    
    return 0;
}

