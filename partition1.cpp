#include <iostream>
#include <vector>
#include <string>

class Solution
{
private:
    std::vector<std::vector<std::string> > res;

private:
    bool isPalindrome(const std::string& s, int beg, int end)
    {
        while (beg < end)
        {
            if (s[beg] != s[end])
            {
                return false;
            }
            ++beg;
            --end;
        }
        return true;
    }
    
    void dfs(const std::string& s, int n, int beg,
             std::vector<std::string>& v)
    {
        if (beg == n)
        {
            if (!v.empty())
            {
                res.push_back(v);
            }
            return ;
        }
        for (int i = beg; i < n; ++i)
        {
            if (isPalindrome(s, beg, i))
            {
                v.push_back(s.substr(beg, i-beg+1));
                dfs(s, n, i+1, v);
                v.pop_back();
            }
        }
    }
    
public:
    std::vector<std::vector<std::string> > partition(std::string s)
    {
        std::vector<std::string> v;
        res.clear();
        dfs(s, s.length(), 0, v);
        return res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::string s;
    while (std::cin >> s)
    {
        std::vector<std::vector<std::string> > res = sln.partition(s);
        for (auto vec : res)
        {
            for (auto item : vec)
            {
                std::cout << item << " ";
            }
            std::cout << std::endl;
        }
    }
    
    return 0;
}

