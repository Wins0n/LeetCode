#include <iostream>
#include <vector>

class Solution
{
private:
    std::vector<int> _v;
    std::vector<std::vector<int> > _res;

private:
    void dfs(int beg, int end, int count)
    {
        if (count == 0)
        {
            _res.push_back(_v);
            return ;
        }

        for (int i = beg; i <= end; ++i)
        {
            _v.push_back(i);
            dfs(i+1, end, count-1);
            _v.pop_back();
        }
    }

public:
    std::vector<std::vector<int> > combine(int n, int k) 
    {
        _res.clear();
        _v.clear();
        dfs(1, n, k);
        return _res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    int n, k;
    
    while (std::cin >> n >> k)
    {
        std::vector<std::vector<int> > res = sln.combine(n, k);
        for (auto v : res)
        {
            for (auto item : v)
            {
                std::cout << item << " ";
            }
            std::cout << std::endl;
        }
    }
    
    return 0;
}

