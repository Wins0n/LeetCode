#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
private:
    std::vector<std::vector<int> > res;

private:
    void dfs(const std::vector<int>& a, int beg, int n, int val,
             std::vector<int>& path)
    {
        if (val < 0)
        {
            return ;
        }
        if (val == 0)
        {
            res.push_back(path);
            return ;
        }
        for (int i = beg; i < n; ++i)
        {
            if (i > 0 && a[i-1] == a[i])
            {
                continue;
            }
            path.push_back(a[i]);
            dfs(a, i, n, val-a[i], path);
            path.pop_back();
        }
    }

public:
    std::vector<std::vector<int> > combinationSum(
        std::vector<int>& candidates,
        int target)
    {
        std::vector<int> path;
        res.clear();
        std::sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, candidates.size(), target, path);
        return res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::vector<int> candidates = {2, 3, 6, 7};

    std::vector<std::vector<int> > v = sln.combinationSum(candidates, 7);
    for (auto vec : v)
    {
        for (auto item : vec)
        {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}

