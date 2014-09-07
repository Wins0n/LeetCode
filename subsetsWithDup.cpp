#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
private:
    std::vector<std::vector<int> > res;

private:
    void dfs(const std::vector<int>& s, int n, int beg,
             int total, int count, std::vector<int>& tmp)
    {
        if (count == total)
        {
            res.push_back(tmp);
            return ;
        }
        for (int i = beg; i < n; ++i)
        {
            if (i > beg && s[i] == s[i-1])
            {
                continue;
            }
            tmp.push_back(s[i]);
            dfs(s, n, i+1, total, count+1, tmp);
            tmp.pop_back();
        }
    }

public:
    std::vector<std::vector<int> > subsetsWithDup(std::vector<int>& s)
    {
        res.clear();
        int n = s.size();
        std::sort(s.begin(), s.end());
        for (int i = 0; i <= n; ++i)
        {
            std::vector<int> tmp;
            dfs(s, n, 0, i, 0, tmp);
        }
        return res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    int n;

    while (std::cin >> n)
    {
        std::vector<int> s(n, 0);
        for (int i = 0; i < n; ++i)
        {
            std::cin >> s[i];
        }
        std::vector<std::vector<int> > res = sln.subsetsWithDup(s);
        for (auto vec : res)
        {
            std::cout << "[";
            for (auto item : vec)
            {
                std::cout << item << ",";
            }
            std::cout << "]" << std::endl;
        }
        std::cout << std::endl;
    }
    
    return 0;
}

