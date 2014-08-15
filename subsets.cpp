#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution
{
private:
    std::vector<std::vector<int> > _res;
    std::vector<int> _v;
    int* arr;

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
            _v.push_back(arr[i]);
            dfs(i+1, end, count-1);
            _v.pop_back();
        }
    }

public:
    std::vector<std::vector<int> > subsets(std::vector<int> &S)
    {
        std::vector<std::vector<int> > res;
        int count = S.size();
        if (count == 0)
        {
            res.push_back(std::vector<int>());
            return res;
        }
        
        _v.clear();
        _res.clear();
        std::sort(S.begin(), S.end());
        arr = &S[0];
        for (int i = 0; i <= count; ++i)
        {
            dfs(0, count-1, i);
            res.insert(res.end(), _res.begin(), _res.end());
            _res.clear();
        }
        
        return res;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    std::vector<int> v = {3, 2, 1};
    std::vector<std::vector<int> > res = sln.subsets(v);

    for (auto vec : res)
    {
        for (auto item : vec)
        {
            std::cout << item << " | ";
        }
        std::cout << std::endl;
    }

    return 0;
}

